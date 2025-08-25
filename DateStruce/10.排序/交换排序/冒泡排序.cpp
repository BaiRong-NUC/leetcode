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
 * 稳定
 */
void BubbleSort(vector<int> &vec)
{
    bool flag = false;
    for (int i = 0; i < vec.size(); i++)
    {
        flag = false;
        for (int j = 0; j < vec.size() - i - 1; j++)
        {
            if(vec[j] > vec[j+1])
            {
                swap(vec[j], vec[j + 1]);
                flag = true;
            }
        }
        if (flag == false)
        {
            break;
        }
    }
}

int main(int argc, char const *argv[])
{
    vector<int> data = {5, 3, 6, 7, 2, 4, 6, 8};
    printVector(data);
    BubbleSort(data);
    printVector(data);
    return 0;
}
