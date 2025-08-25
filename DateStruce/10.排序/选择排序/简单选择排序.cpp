#include <iostream>
#include <vector>
using namespace std;

void printVector(const vector<int> &vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
}

/**
 * 时间复杂度O(n^2)
 * 空间复杂度O(1)
 * 不稳定
*/
void selectionSort(vector<int> &vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        int maxPos = 0;
        //找最大值
        for (int j = 1; j < vec.size() - i; j++)
        {
            if (vec[j] > vec[maxPos])
            {
                maxPos = j;
            }
        }
        swap(vec[vec.size() - i - 1], vec[maxPos]);
    }
}

int main(int argc, char const *argv[])
{
    vector<int> data = {5, 3, 6, 7, 2, 4, 6, 8};
    printVector(data);
    selectionSort(data);
    printVector(data);
    return 0;
}
