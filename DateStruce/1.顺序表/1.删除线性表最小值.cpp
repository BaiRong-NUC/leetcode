#define MAX_SIZE 10
#include <iostream>
/**
 * 从顺序表中删除具有最小值的元素(假设唯一)并由函数返回被删元素的值。
 * 空出的位置由最后一个元素填补，若顺序表为空，则显示出错信息并退出运行。
 */
typedef struct
{
    // 顺序表的元素
    int data[MAX_SIZE];
    // 顺序表的长度
    int length;
} Array;

// 删除最小值
bool DeleteMin(Array &array, int &ret)
{
    if (array.length == 0)
    {
        printf("顺序表为空");
        return false;
    }
    else
    {
        int minPos = 0;
        for (int i = 1; i < array.length; i++)
        {
            if (array.data[i] < array.data[minPos])
            {
                minPos = i;
            }
        }
        ret = array.data[minPos];
        array.data[minPos] = array.data[array.length - 1];
        array.length--;
        return true;
    }
}

// 打印顺序表
void PrintArray(Array &array)
{
    if (array.length == 0)
    {
        printf("顺序表为空");
    }
    else
    {
        for (int i = 0; i < array.length; i++)
        {
            printf("%d ", array.data[i]);
        }
    }
}

int main(int argc, char const *argv[])
{
    Array array;
    array.length = 1;
    for (int i = 0; i < array.length; i++)
    {
        array.data[i] = i;
    }
    int buff = 0;
    DeleteMin(array, buff);
    PrintArray(array);
    return 0;
}