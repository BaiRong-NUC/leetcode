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

void exchange(ArrayList &arrayList, int m, int n)
{
    int left = m;
    int right = n;
    while (left < right)
    {
        swap(arrayList.data[left], arrayList.data[right]);
        left++;
        right--;
    }
}

void exchangeArrayList(ArrayList &arrayList, int m, int n)
{
    if (m < 0 || m > arrayList.length || n < 0 || n > arrayList.length || (m + n) > arrayList.length)
    {
        return;
    }
    exchange(arrayList, 0, arrayList.length - 1);
    exchange(arrayList, 0, n - 1);
    exchange(arrayList, n, arrayList.length - 1);
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
    exchangeArrayList(arrayList, 3, arrayList.length - 3);
    printArrayList(arrayList);
    return 0;
}
