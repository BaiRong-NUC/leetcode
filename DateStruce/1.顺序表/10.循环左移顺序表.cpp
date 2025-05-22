#include <iostream>
using namespace std;
#define MAX_SIZE 20
typedef int ElemType;
typedef struct ArrayList
{
    ElemType data[MAX_SIZE];
    int length;
} ArrayList;

void printArrayList(const ArrayList &arrayList)
{
    for (int i = 0; i < arrayList.length; i++)
    {
        cout << arrayList.data[i] << " ";
    }
    cout << endl;
}

void Exchange(ArrayList &arrayList, int left, int right)
{
    while (left <= right)
    {
        swap(arrayList.data[left], arrayList.data[right]);
        left++;
        right--;
    }
}

void ExchangeArrayList(ArrayList &arrayList, int k)
{
    if (k < 0 || k > arrayList.length)
    {
        return;
    }
    Exchange(arrayList, 0, arrayList.length - 1);                    // 整体交换
    Exchange(arrayList, 0, arrayList.length - k - 1);                // 前k个元素交换
    Exchange(arrayList, arrayList.length - k, arrayList.length - 1); // 后k个元素交换
}

// 将顺序表前k个元素循环右移k个位置
void leftShift(ArrayList &arrayList, int k)
{
    if (k < 0)
    {
        cout << "k<0" << endl;
        return;
    }
    k = k % arrayList.length; // 防止k>arrayList.length
    ExchangeArrayList(arrayList, k);
}

int main(int argc, char const *argv[])
{
    ArrayList arrayList;
    arrayList.length = 10;
    for (int i = 0; i < arrayList.length; i++)
    {
        arrayList.data[i] = i;
    }
    printArrayList(arrayList);
    leftShift(arrayList, 10); // 循环右移10个位置
    printArrayList(arrayList);
    return 0;
}
