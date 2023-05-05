/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 */

#include <vector>

using namespace std;

// @lc code=start

/**
Accepted
19/19 cases passed (0 ms)
Your runtime beats 100 % of cpp submissions
Your memory usage beats 79.68 % of cpp submissions (5.8 MB)
 */
class Solution
{
public:
    int numTrees(int n)
    {
        vector<int> dp(n + 1); // dp[i] = i个不同的数组成的二叉搜索数的个数
        dp[0] = dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }
        return dp[n];
    }
};
// @lc code=end
