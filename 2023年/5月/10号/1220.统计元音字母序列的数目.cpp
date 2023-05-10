/*
 * @lc app=leetcode.cn id=1220 lang=cpp
 *
 * [1220] 统计元音字母序列的数目
 */

#include <vector>
#include <algorithm>

using namespace std;

/**
Accepted
43/43 cases passed (48 ms)
Your runtime beats 47.53 % of cpp submissions
Your memory usage beats 13.58 % of cpp submissions (26.7 MB)
 */

// @lc code=start
class Solution
{
public:
    int countVowelPermutation(int n)
    {
        long long MODULO = 1e9 + 7;
        vector<vector<long>> dp(n, vector<long>(5));
        for (int i = 0; i < 5; i++)
        {
            dp[n - 1][i] = 1;
        }
        for (int i = n - 2; i >= 0; i--)
        {
            dp[i][0] = dp[i + 1][1];
            dp[i][1] = (dp[i + 1][0] + dp[i + 1][2]) % MODULO;
            dp[i][2] = (dp[i + 1][0] + dp[i + 1][1] + dp[i + 1][3] + dp[i + 1][4]) % MODULO;
            dp[i][3] = (dp[i + 1][2] + dp[i + 1][4]) % MODULO;
            dp[i][4] = dp[i + 1][0];
        }
        long total = 0;
        for (long count : dp[0])
        {
            total += count;
        }
        return (int)(total % MODULO);
    }
};
// @lc code=end
