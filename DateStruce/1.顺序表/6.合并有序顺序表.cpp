// 06.将两个有序顺序表合并为一个新的有序顺序表，并由函数返回结果顺序表。
#include <iostream>
#define MAX_SIZE 20
typedef int ElemType;
typedef struct Array
{
    ElemType data[MAX_SIZE];
    int length;
} Array;

void PrintArray(const Array &array)
{
    if (array.length == 0)
    {
        printf("顺序表为空\n");
    }
    else
    {
        for (int i = 0; i < array.length; i++)
        {
            printf("%d ", array.data[i]);
        }
        printf("\n");
    }
}

Array MergeArray(Array &left, Array &right)
{
    Array ret;
    ret.length = left.length + right.length;
    int leftPos = 0, rightPos = 0, retPos = 0;
    while (leftPos < left.length && rightPos < right.length)
    {
        if (left.data[leftPos] < right.data[rightPos])
        {
            ret.data[retPos] = left.data[leftPos];
            leftPos += 1;
        }
        else
        {
            ret.data[retPos] = right.data[rightPos];
            rightPos += 1;
        }
        retPos += 1;
    }
    // 至少有一个走到的末尾
    while (leftPos < left.length)
    {
        ret.data[retPos] = left.data[leftPos];
        leftPos += 1;
        retPos += 1;
    }
    while (rightPos < right.length)
    {
        ret.data[retPos] = right.data[rightPos];
        rightPos += 1;
        retPos += 1;
    }
    return ret;
}

int main(int argc, char const *argv[])
{
    Array left;
    left.length = 10;
    for (int i = 0; i < left.length; i++)
    {
        left.data[i] = i + 2;
    }
    PrintArray(left);
    Array right;
    right.length = 10;
    for (int i = 0; i < right.length; i++)
    {
        right.data[i] = i + 1;
    }
    PrintArray(right);

    PrintArray(MergeArray(left, right));
    return 0;
}
