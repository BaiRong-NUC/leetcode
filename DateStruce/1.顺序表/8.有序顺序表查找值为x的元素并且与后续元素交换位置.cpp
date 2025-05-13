/**
 * 线性表(a1, a2, a3,…,an,)中的元素递增有序且按顺序存储于计算机内。要求设计一个算法,
 * 完成用最少时间在表中查找数值为x的元素，若找到，则将其与后继元素位置相交换，
 * 若找不到，则将其插入表中并使表中元素仍递增有序。
 */
#include <iostream>
using namespace std;
#define MAX_SIZE 20
typedef int ElemType;
typedef struct ArrayList
{
    ElemType data[MAX_SIZE];
    int length;
} ArrayList;

void printArrayList(ArrayList &arrayList)
{
    for (int i = 0; i < arrayList.length; i++)
    {
        cout << arrayList.data[i] << " ";
    }
    cout << endl;
}

// arrayList 有序顺序表
void searchAndSwap(ArrayList &arrayList, ElemType x)
{
    // 折半查找第一次出现x的位置
    int low = 0;
    int high = arrayList.length - 1; //[left,right]
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arrayList.data[mid] < x)
        {
            low = mid + 1;
        }
        else if (arrayList.data[mid] > x)
        {
            high = mid - 1;
        }
        else
        {
            // arrayList.data[mid]==x
            // 找第一次出现的x,此时high=mid-1
            high = mid - 1;
        }
    }
    // low为第一次出现x的位置,或者是要插入的位置
    if (low < arrayList.length && arrayList.data[low] == x)
    {
        // 找到元素
        int left = low, right = low;
        while (right != arrayList.length && arrayList.data[left] == arrayList.data[right])
        {
            right++;
        }

        if (right == arrayList.length)
            return; // 整个数组全部是x

        // 合法位置，将[left,right-1]的元素和[right,length-1]的元素交换
        int swapLen = arrayList.length - right;
        for (int i = 0; i < swapLen; i++)
        {
            swap(arrayList.data[left + i], arrayList.data[right + i]);
        }
    }
    else
    {
        // 没有找到元素,low为要插入的位置
        // 检测数组是否满了
        if (arrayList.length == MAX_SIZE)
        {
            cout << "数组已满" << endl;
            return;
        }

        // 插入元素
        for (int i = arrayList.length; i > low; i--)
        {
            arrayList.data[i] = arrayList.data[i - 1];
        }
        arrayList.data[low] = x;
        arrayList.length++;
    }
}

int main(int argc, char const *argv[])
{
    ArrayList arrayList;
    arrayList.length = 5;
    for (int i = 0; i < arrayList.length; i++)
    {
        arrayList.data[i] = i;
    }
    arrayList.data[1] = 0;
    arrayList.data[2] = 0;
    printArrayList(arrayList);
    searchAndSwap(arrayList, 0);
    printArrayList(arrayList);
    return 0;
}
