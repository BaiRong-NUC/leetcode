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
/**思路:
 * 直接插入排序算法当排序序列近似有序的时候效率是最高的,希尔排序的思路是先大跨步的将数据排列的尽可能有序,最后将跨度设置为1,进行插入排序
 */
/**
 * 稳定性:稳定
 * 时间复杂度:O(N^2)
 * 空间复杂度:O(1)
 */
// 从小到大排序
void ShellSort(vector<int> &vec)
{
    int step = vec.size(); // 初始步长
    while (step > 1)
    {
        // step最小为1,保证至少进行一次插入排序
        step = step / 3 + 1;
        // 当前i就是endPos，下一个元素endPos+step,下一个元素一定不能越界，所以就要保证endPos+step<vec.size()，所以要保证endPos<vec.size()-step,endPos就是i,所以i就要小于vec.size()-step
        for (int i = 0; i < vec.size() - step; i++)
        {
            // 大的插入排序
            int endPos = i;
            int nextValue = vec[endPos + step];
            while (endPos >= 0)
            {
                if (nextValue < vec[endPos])
                {
                    vec[endPos + step] = vec[endPos]; // 向后移动
                    endPos -= step;
                }
                else
                {
                    break;
                }
            }
            // nextValue要插入的位置就是endPos+step
            vec[endPos + step] = nextValue;
        }
    }
}
int main(int argc, char const *argv[])
{
    vector<int> data = {5, 3, 6, 7, 2, 4, 6, 8};
    printVector(data);
    ShellSort(data);
    printVector(data);
    return 0;
}
