/*
 * @lc app=leetcode.cn id=1027 lang=cpp
 *
 * [1027] 最长等差数列
 */

#include <vector>
#include <unordered_map>

using namespace std;
/**
动态规划

状态定义：dp[i][d]表示以nums[i]结尾且公差为d的数列长度。

状态转移：对于nums[i]，可以枚举它的前一项nums[j]，0<= j < i，有了前一项nums[j]，其实公差就确定了d=nums[i]-nums[j]。

如果nums[j]可以是某个公差为d的数列的最后一项，nums[i]就可以接在后面形成更长的等差数列，状态转移方程为dp[i][d]=dp[j][d]+1

否则它两就形成公差为d的等差数列前两项，状态转移方程为dp[i][d]=2。
 */

/**
Accepted
63/63 cases passed (1596 ms)
Your runtime beats 7.82 % of cpp submissions
Your memory usage beats 9.85 % of cpp submissions (238.4 MB)
 */

// @lc code=start
class Solution
{
public:
    int longestArithSeqLength(vector<int> &nums)
    {
        vector<unordered_map<int, int>> dp(nums.size());
        int ret = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                int difference = nums[i] - nums[j];
                if (dp[j].count(difference))
                {
                    dp[i][difference] = dp[j][difference] + 1;
                }
                else
                {
                    dp[i][difference] = 2;
                }
                ret = max(ret, dp[i][difference]);
            }
        }
        return ret;
    }
};
// @lc code=end
