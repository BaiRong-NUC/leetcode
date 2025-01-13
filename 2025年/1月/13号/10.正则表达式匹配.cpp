/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 */
#include <D:/CppCode/leetcode/global/global.h>
/**
 * Accepted
    354/354 cases passed (27 ms)
    Your runtime beats 12.45 % of cpp submissions
    Your memory usage beats 5.03 % of cpp submissions (25.2 MB)
 */
// @lc code=start
class Solution
{
    // 记录src[i-end]和dst[j-end]是否匹配，方便递归时查询结果，避免重复计算
    unordered_map<string, bool> hash;
    // dp[i][j]表示s[i-end]和p[j-end]是否匹配
    // s称为待匹配串，p称为匹配串
    bool dp(string s, int i, string p, int j)
    {
        // 递归出口
        if (j == p.size())
        {
            // 匹配串到末尾，看待匹配串是否也到末尾
            return i == s.size();
        }
        // 递归出口
        else if (i == s.size())
        {
            // 待匹配串匹配完毕，匹配串没有到末尾
            // 匹配串只能是字母+*的组合
            //  eg:1. x*y*z*  2. .*.* 这个*使得前一个字母匹配0次
            int len = p.size() - j;
            if (len % 2 == 1)
            {
                // 匹配串剩余字母数为奇数，不可能匹配
                return false;
            }
            // 检查是否是字母+*的组合
            for (int begin = j; begin < p.size(); begin += 2)
            {
                if (p[begin + 1] != '*')
                {
                    return false;
                }
            }
            // 检测完毕，正确匹配
            return true;
        }
        // 一般情况（递归部分）
        else
        {
            string key = to_string(i) + "," + to_string(j);
            if (hash.count(key))
            {
                // 找到答案
                return hash[key];
            }
            // 未找到答案
            bool ret = false;
            if (s[i] == p[j] || p[j] == '.')
            {
                if (j + 1 < p.size() && p[j + 1] == '*')
                {
                    // 匹配串下一个字符是*
                    // dp(s, i, p, j + 2)表面*前的字母没有使用，dp(s, i + 1, p, j)表示*前字母使用1次
                    ret = dp(s, i, p, j + 2) || dp(s, i + 1, p, j);
                }
                else
                {
                    // 两个串都匹配一个字符
                    ret = dp(s, i + 1, p, j + 1);
                }
            }
            else
            {
                if (j + 1 < p.size() && p[j + 1] == '*')
                {
                    // 匹配串下一个字符是*
                    // 匹配串*前的字符和待匹配串当前字符不匹配，只能让*前字母匹配0次
                    ret = dp(s, i, p, j + 2);
                }
                else
                {
                    // 不可能匹配
                    ret = false;
                }
            }
            hash[key] = ret;
            return ret;
        }
    }

public:
    bool isMatch(string s, string p)
    {
        return dp(s, 0, p, 0);
    }
};
// @lc code=end
