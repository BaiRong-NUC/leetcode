// 从顺序表中删除其值在给定值s和t之间(包含s和t，要求s < t) 的所有元素，若s或不合理或顺序表为空，则显示出错信息并退出运行
#define MAX_SIZE 10
#include <iostream>
using namespace std;
typedef int ElemType;
typedef struct Array
{
    ElemType data[MAX_SIZE];
    int length;
} Array;
void DeleteST(Array &array, ElemType s, ElemType t)
{
    if (array.length == 0 || s > t)
    {
        printf("顺序表为空或s > t");
    }
    else
    {
        int slow = 0;
        int fast = 0;
        while (fast < array.length)
        {
            if (array.data[fast] < s || array.data[fast] > t)
            {
                array.data[slow] = array.data[fast];
                slow++;
            }
            fast++;
        }
        array.length = slow;
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
    DeleteST(array, 0, 11);
    PrintArray(array);
    return 0;
}
