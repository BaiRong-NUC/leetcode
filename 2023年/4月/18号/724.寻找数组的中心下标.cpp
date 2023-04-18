/*
 * @lc app=leetcode.cn id=724 lang=cpp
 *
 * [724] 寻找数组的中心下标
 */

#include <vector>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution
{
public:
    int pivotIndex(vector<int> &nums)
    {
        int total = accumulate(nums.begin(), nums.end(), 0);
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (2 * sum + nums[i] == total)
            {
                return i;
            }
            sum += nums[i];
        }
        return -1;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> ret{1, 2, 3};
    solution.pivotIndex(ret);
    return 0;
}
