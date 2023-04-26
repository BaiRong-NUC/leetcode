/*
 * @lc app=leetcode.cn id=1218 lang=cpp
 *
 * [1218] 最长定差子序列
 */

#include <vector>
#include <unordered_map>
using namespace std;

// @lc code=start
class Solution
{
public:
    int longestSubsequence(vector<int> &arr, int difference)
    {
        unordered_map<int, int> dp;
        int ret = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            dp[arr[i]] = dp[arr[i] - difference] + 1;
            ret = max(ret, dp[arr[i]]);
        }
        return ret;
    }
};
// @lc code=end
