/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 */

#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

/**
Accepted
45/45 cases passed (16 ms)
Your runtime beats 57.72 % of cpp submissions
Your memory usage beats 47.88 % of cpp submissions (12.9 MB)
 */

// @lc code=start
class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        unordered_set<string> _hash;
        for (int i = 0; i < wordDict.size(); i++)
        {
            _hash.insert(wordDict[i]);
        }

        vector<bool> dp(s.length() + 1, false);
        // dp[i]表示s前i个字符是否能被wordDict表示
        dp[0] = true;
        for (int i = 0; i <= s.length(); i++)
        {
            // 在0-i中拆分单词[0,j] [j+1,i]
            for (int j = 0; j < i; j++)
            {
                if (dp[j] == true && _hash.find(s.substr(j, i - j)) != _hash.end())
                {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};
// @lc code=end
