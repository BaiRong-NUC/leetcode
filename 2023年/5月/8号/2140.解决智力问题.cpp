/*
 * @lc app=leetcode.cn id=2140 lang=cpp
 *
 * [2140] 解决智力问题
 */

#include <vector>

/**
Accepted
54/54 cases passed (376 ms)
Your runtime beats 15.21 % of cpp submissions
Your memory usage beats 21.29 % of cpp submissions (112.7 MB)
 */

using namespace std;

// @lc code=start
class Solution
{
public:
    long long mostPoints(vector<vector<int>> &questions)
    {
        int size = questions.size();
        // dp[i]表示解决第i题之后包括第i题，可以获得的最大分数
        vector<long long> dp(questions.size() + 1);
        // 填表法
        for (int i = questions.size() - 1; i >= 0; i--)
        {

            dp[i] = max(dp[i + 1], dp[min(size, i + questions[i][1] + 1)] + questions[i][0]);
        }
        return dp[0];
    }
};
// @lc code=end
