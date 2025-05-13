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

ArrayList findCommonElements(ArrayList &a, ArrayList &b, ArrayList &c)
{
    ArrayList ret;
    ret.length = 0;
    int posA = 0, posB = 0, posC = 0;
    while (posA < a.length && posB < b.length && posC < c.length)
    {
        if (a.data[posA] == b.data[posB] && b.data[posB] == c.data[posC])
        {
            ret.data[ret.length] = a.data[posA];
            ret.length++;
            posA++, posB++, posC++;
        }
        else
        {
            // 最小的元素pos位置+1
            int minVal = min(a.data[posA], min(b.data[posB], c.data[posC]));
            if (a.data[posA] == minVal)
                posA++;
            else if (b.data[posB] == minVal)
                posB++;
            else if (c.data[posC] == minVal)
                posC++;
        }
    }
    return ret;
}

int main(int argc, char const *argv[])
{
    ArrayList a;
    a.length = 5;
    for (int i = 0; i < a.length; i++)
    {
        a.data[i] = i + 1;
    }
    printArrayList(a);
    ArrayList b;
    b.length = 5;
    for (int i = 0; i < b.length; i++)
    {
        b.data[i] = i;
    }
    printArrayList(b);
    ArrayList c;
    c.length = 5;
    for (int i = 0; i < c.length; i++)
    {
        c.data[i] = i + 2;
    }
    printArrayList(c);

    printArrayList(findCommonElements(a, b, c));
    return 0;
}
