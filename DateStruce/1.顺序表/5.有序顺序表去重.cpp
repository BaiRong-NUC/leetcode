// 从有序顺序表中删除所有其值重复的元素，使表中所有元素的值均不同。
#define MAX_SIZE 10
#include <iostream>
using namespace std;
typedef int ElemType;
typedef struct Array
{
    ElemType data[MAX_SIZE];
    int length;
} Array;

void DeleteSame(Array &array)
{
    if (array.length == 0)
    {
        return;
    }
    else
    {
        int slow = 0;
        int fast = 1;
        while (fast < array.length)
        {
            // 找下一个不相等元素
            while (fast < array.length && array.data[fast] == array.data[slow])
            {
                fast++;
            }
            // 找到下一个不相等元素
            if (fast < array.length)
            {
                slow++;
                array.data[slow] = array.data[fast];
                fast++;
            }
        }
        array.length = slow + 1;
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
    array.length = 10;
    for (int i = 0; i < array.length; i++)
    {
        array.data[i] = i;
    }
    array.data[0] = 2;
    array.data[1] = 2;
    array.data[3] = 2;
    DeleteSame(array);
    PrintArray(array);
    return 0;
}
