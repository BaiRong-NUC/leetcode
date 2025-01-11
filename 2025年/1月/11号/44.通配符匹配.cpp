/*
 * @lc app=leetcode.cn id=44 lang=cpp
 *
 * [44] 通配符匹配
 */
#include <D:/CppCode/leetcode/global/global.h>
// @lc code=start
class Solution
{
    unordered_map<string, bool> hash;
    /**
     * Memory Limit Exceeded
     * 1807/1811 cases passed (N/A)
        Testcase
        "aaabaaabbababaabbabaababbbbbbaabababbbaabaaaabbbbabbbbaaaaabaabbbbaaaabbabbaaabbabbbababbaaaabbabbabbbbabaabbabbbabbbbabbbbbaabbbababaaaababbbbababababababbabbbbaaaaababbaaababbabaababbbaaabbbbbababab"
        ' +
        '"aa*abab*a*a**a*b****ba*ba*aa*****b****b**bbbba*b*b*a**b**b*aab***b*bb***baa*b***a***baa*****a*a*a*ab**a"
     */
    // // dp[i][j]表示s[i-end]和p[j-end]是否匹配
    // bool dp(string src, int s, string dst, int p)
    // {
    //     // 递归出口
    //     if (p == dst.size())
    //     {
    //         return s == src.size();
    //     }
    //     else if (s == src.size())
    //     {
    //         // 剩下的都是*
    //         for (int i = p; i < dst.size(); ++i)
    //         {
    //             if (dst[i] != '*')
    //             {
    //                 return false;
    //             }
    //         }
    //         return true;
    //     }
    //     // 一般情况
    //     else
    //     {
    //         string key = to_string(s) + "," + to_string(p);
    //         if (hash.count(key)) // 找到答案
    //         {
    //             return hash[key];
    //         }
    //         else
    //         {
    //             bool ret = false;
    //             if (src[s] == dst[p] || dst[p] == '?')
    //             {
    //                 ret = dp(src, s + 1, dst, p + 1);
    //             }
    //             else
    //             {
    //                 if (dst[p] == '*')
    //                 {
    //                     ret = dp(src, s + 1, dst, p) || dp(src, s, dst, p + 1);
    //                 }
    //                 else
    //                 {
    //                     ret = false;
    //                 }
    //             }
    //             hash[key] = ret;
    //             return ret;
    //         }
    //     }
    // }

public:
    bool isMatch(string s, string p)
    {
        // return dp(s, 0, p, 0);
        // dp[i][j]表示s[0-i]和p[0-j]是否匹配
        vector<vector<bool>> dp(s.size() + 1, vector<bool>(p.size() + 1, false));
        // 初始化
        dp[0][0] = true;
        for (int i = 1; i <= p.size(); ++i)
        {
            if (p[i - 1] == '*')
            {
                dp[0][i] = true;
            }
            else
            {
                break;
            }
        }
        for (int i = 1; i <= s.size(); ++i)
        {
            for (int j = 1; j <= p.size(); ++j)
            {
                if (p[j - 1] == '*')
                {
                    // dp[i][j-1]代表使用*匹配src[i-1],dp[i-1][j]代表不使用*直接跳过
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
                }
                else if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = false;
                }
            }
        }
        return dp[s.size()][p.size()];
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution sol;
    cout << sol.isMatch("aab", "c*a*b");
    return 0;
}
