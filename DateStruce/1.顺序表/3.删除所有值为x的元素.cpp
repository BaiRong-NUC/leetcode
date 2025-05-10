// 对长度为n的顺序表L，编写一个时间复杂度为 0(n)、空间复杂度为 O(1) 的算法，该算法删除顺序表中所有值为x的数据元素
#include <iostream>
#define MAX_SIZE 10

typedef int ElemType;

typedef struct Array
{
    ElemType data[MAX_SIZE];
    int length;
} Array;

void DeleteX(Array &array, ElemType x)
{
    // 快慢指针
    int slow = 0;
    int fast = 0;
    while (fast < array.length)
    {
        if (array.data[fast] != x)
        {
            array.data[slow] = array.data[fast];
            slow++;
        }
        fast++;
    }
    array.length = slow;
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
    array.length = 10;
    for (int i = 0; i < array.length; i++)
    {
        array.data[i] = 1;
    }
    DeleteX(array, 1);
    PrintArray(array);
    return 0;
}
