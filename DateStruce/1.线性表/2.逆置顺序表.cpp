// 设计一个高效算法，将顺序表L的所有元素逆置，要求算法的空间复杂度为 0(1)。
#define MAX_SIZE 10
#include <iostream>
typedef int ElemType;

typedef struct Array
{
    ElemType data[MAX_SIZE];
    int length;
} Aeeay;

void Reverse(Array &array)
{
    // 左右指针
    int left = 0;
    int right = array.length - 1;
    while (left < right)
    {
        // 交换
        int temp = array.data[left];
        array.data[left] = array.data[right];
        array.data[right] = temp;
        // 移动指针
        left++;
        right--;
    }
}

void PrintArray(Array &array)
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

int main(int argc, char const *argv[])
{
    Array array;
    array.length = 0;
    for (int i = 0; i < array.length; i++)
    {
        array.data[i] = i;
    }
    PrintArray(array);
    Reverse(array);
    PrintArray(array);
    return 0;
}
