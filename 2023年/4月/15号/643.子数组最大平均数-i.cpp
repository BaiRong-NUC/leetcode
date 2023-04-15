/*
 * @lc app=leetcode.cn id=643 lang=cpp
 *
 * [643] 子数组最大平均数 I
 */

#include <vector>
#include <iostream>
#include <algorithm>
#include <float.h>
using namespace std;

// @lc code=start
class Solution
{
public:
    double findMaxAverage(vector<int> &nums, int k)
    {
        // 滑动窗口
        int l = 0, sum = 0, ret = INT_MIN;
        for (int r = 0; r < nums.size(); ++r)
        {
            sum += nums[r];
            if (r - l + 1 == k)
            {
                ret = max(ret, sum);
                sum -= nums[l];
                ++l;
            }
        }
        // 过程中用int计算效率更高，最后返回时强转为double即可
        return (double)ret / k;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> ret{-1};
    solution.findMaxAverage(ret, 1);
    return 0;
}
