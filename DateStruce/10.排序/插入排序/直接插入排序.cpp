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
 * 设计的排序算法是稳定的
 * 时间复杂度:O(n^2) 如果数据基本有序O(N)
 * 空间复杂度:O(1)
 */
// 直接插入排序,从小到大排列
void insertSort(vector<int> &vec)
{
    for (int i = 0; i < vec.size() - 1; i++)
    {
        int endPos = i;
        int nextValue = vec[endPos + 1];
        // 找nextValue的插入位置
        while (endPos >= 0)
        {
            if (vec[endPos] > nextValue)
            {
                vec[endPos + 1] = vec[endPos]; // 向后移动
                endPos -= 1;
            }
            else
            {
                break;
            }
        }
        // nextValue要插入的位置就是endPos+1
        vec[endPos + 1] = nextValue;
    }
}

int main(int argc, char const *argv[])
{
    vector<int> data = {5, 3, 6, 7, 2, 4, 6, 8};
    printVector(data);
    insertSort(data);
    printVector(data);
    return 0;
}
