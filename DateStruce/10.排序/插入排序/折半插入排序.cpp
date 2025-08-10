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

// 二分查找nextValue要插入的位置
int binarySearch(const vector<int> &vec, int nextValue, int endPos)
{
    // 找nextValue要插入的位置[0,endPos]
    int left = 0;
    int right = endPos;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (vec[mid] > nextValue)
        {
            right = mid - 1; // nextValue在左边
        }
        else if (vec[mid] < nextValue)
        {
            left = mid + 1; // nextValue在右边
        }
        else
        {
            left = mid + 1; // 保证折半插入排序算法的稳定
        }
    }
    // 跳出循环后left就是要插入的位置
    return left;
}
/**
 * 稳定性:稳定的
 * 时间复杂度:O(N^2)
 * 空间复杂度:O(1)
 */
// 升序排列
void binaryInsertSort(vector<int> &vec)
{
    for (int i = 0; i < vec.size() - 1; i++)
    {
        int endPos = i;
        int nextValue = vec[endPos + 1];
        int insertPos = binarySearch(vec, nextValue, endPos); // 找到要插入的位置了
        // 向后移动下标insertPos到endPos的元素，将这些元素放到[insertPos+1,endPos+1]这个位置.最后将nextValue放到insertPos位置
        for (int j = endPos; j >= insertPos; j--)
        {
            vec[j + 1] = vec[j];
        }
        vec[insertPos] = nextValue;
    }
}

int main(int argc, char const *argv[])
{
    vector<int> data = {5, 3, 6, 7, 2, 4, 6, 8};
    printVector(data);
    binaryInsertSort(data);
    printVector(data);
    return 0;
}
