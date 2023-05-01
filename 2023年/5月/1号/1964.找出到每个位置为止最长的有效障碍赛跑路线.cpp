/*
 * @lc app=leetcode.cn id=1964 lang=cpp
 *
 * [1964] 找出到每个位置为止最长的有效障碍赛跑路线
 */

#include <vector>
#include <algorithm>

using namespace std;

/**
Accepted
78/78 cases passed (232 ms)
Your runtime beats 70.48 % of cpp submissions
Your memory usage beats 46.39 % of cpp submissions (120.1 MB)
 */

// @lc code=start
class Solution
{
public:
    // 贪心+动态规划
    vector<int> longestObstacleCourseAtEachPosition(vector<int> &obstacles)
    {
        vector<int> ret;
        vector<int> dp; // dp[i]的值代表 长度为 i+1 的子序列尾部元素的值。
        for (int i = 0; i < obstacles.size(); i++)
        {
            if (dp.empty() || dp.back() <= obstacles[i])
            {
                dp.push_back(obstacles[i]);
                ret.push_back(dp.size());
            }
            else
            {
                // 找第一个大于obstacles[i]的位置
                int pos = upper_bound(dp.begin(), dp.end(), obstacles[i]) - dp.begin();
                ret.push_back(pos + 1);
                dp[pos] = obstacles[i];
            }
        }
        return ret;
    }

    // 动态规划超时
    //  vector<int> longestObstacleCourseAtEachPosition(vector<int> &obstacles)
    //  {
    //      vector<int> ret;
    //      vector<int> dp(obstacles.size(), 0);
    //      for (int i = 0; i < obstacles.size(); i++)
    //      {
    //          dp[i] = 1;
    //          for (int j = 0; j < i; j++)
    //          {
    //              if (obstacles[j] <= obstacles[i])
    //              {
    //                  dp[i] = max(dp[i], dp[j] + 1);
    //              }
    //          }
    //          ret.push_back(dp[i]);
    //      }
    //      return ret;
    //  }
};
// @lc code=end
