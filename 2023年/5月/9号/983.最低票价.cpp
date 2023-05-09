/*
 * @lc app=leetcode.cn id=983 lang=cpp
 *
 * [983] 最低票价
 */

#include <vector>

using namespace std;

/**
Accepted
70/70 cases passed (4 ms)
Your runtime beats 70.41 % of cpp submissions
Your memory usage beats 59.17 % of cpp submissions (9.3 MB)
 */

// @lc code=start
class Solution
{
public:
    int mincostTickets(vector<int> &days, vector<int> &costs)
    {
        int firstday = days[0];
        int lastday = days.back();
        vector<int> dp(lastday + 31); // dp[i] 表示到第i天结束时的最低消费
        for (int day = lastday, pos = days.size() - 1; day >= firstday; day--)
        {
            if (day == days[pos])
            {
                dp[day] = min(dp[day + 1] + costs[0], min(dp[day + 7] + costs[1], dp[day + 30] + costs[2]));
                pos -= 1;
            }
            else
            {
                dp[day] = dp[day + 1];
            }
        }
        return dp[firstday];
    }
};
// @lc code=end
