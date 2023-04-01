/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] 斐波那契数
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution
{
public:
    int fib(int n)
    {
        if (n <= 1)
        {
            return n;
        }
        vector<int> dp;
        dp.push_back(0);
        dp.push_back(1);
        for (int i = 2; i <= n; i++)
        {
            dp.push_back(dp[i - 1] + dp[i - 2]);
        }
        return dp[n];
    }
};
// @lc code=end
