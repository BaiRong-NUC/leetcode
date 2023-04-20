/*
 * @lc app=leetcode.cn id=1137 lang=cpp
 *
 * [1137] 第 N 个泰波那契数
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution
{
public:
    int tribonacci(int n)
    {
        int size = n > 3 ? n + 1 : 4;
        vector<int> dp(size, 0);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;

        for (int i = 3; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
        }
        return dp[n];
    }
};
// @lc code=end
