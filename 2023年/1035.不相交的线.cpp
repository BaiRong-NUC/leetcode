/*
 * @lc app=leetcode.cn id=1035 lang=cpp
 *
 * [1035] 不相交的线
 */

#include <vector>

using namespace std;

/**
Accepted
74/74 cases passed (8 ms)
Your runtime beats 97.84 % of cpp submissions
Your memory usage beats 48.02 % of cpp submissions (12.6 MB)
 */

// @lc code=start
class Solution
{
public:
    int maxUncrossedLines(vector<int> &nums1, vector<int> &nums2)
    {
        // 不相交的线，最长公共序列
        int row = nums1.size();
        int col = nums2.size();
        vector<vector<int>> dp(row + 1, vector<int>(col + 1, 0)); // dp[i][j]nums1长度为i,nums2长度为j的最长公共子序列
        for (int i = 1; i <= nums1.size(); i++)
        {
            for (int j = 1; j <= nums2.size(); j++)
            {
                if (nums1[i - 1] == nums2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[row][col];
    }
};
// @lc code=end
