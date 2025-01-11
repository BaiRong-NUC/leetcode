/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 */
#include <D:/CppCode/leetcode/global/global.h>
// @lc code=start
class Solution
{
    // 哈希表记录src[i-end]和dst[j-end]是否匹配
    unordered_map<string, bool> hash;
    // dp[i][j]表示s[i-end]和p[j-end]是否匹配
    bool dp(string src, int s, string dst, int p)
    {
        // cout << src[s] << " " << s << dst[p] << " " << p << endl;
        // 递归出口
        if (p == dst.size())
        {
            // 看s匹配到哪里了
            return s == src.size();
        }
        else if (s == src.size())
        {
            // dst剩下的都是字母+*的组合
            // 如果剩下的字符数为奇数，肯定不匹配
            if ((dst.size() - p) % 2 == 1)
            {
                return false;
            }
            for (int i = p; i < dst.size(); i += 2)
            {
                if (i + 1 < dst.size() && dst[i + 1] == '*')
                {
                    continue;
                }
                else
                {
                    return false;
                }
            }
            return true;
        }
        else
        {
            // 记录当前递归的结果
            string key = to_string(s) + "," + to_string(p);
            if (hash.count(key))
            {
                return hash[key];
            }
            else
            {
                bool ret = false;
                if (src[s] == dst[p] || dst[p] == '.')
                {
                    if (p + 1 < dst.size() && dst[p + 1] == '*')
                    {
                        // 匹配多次
                        ret = dp(src, s + 1, dst, p) || dp(src, s, dst, p + 2);
                    }
                    else
                    {
                        // 匹配一次
                        ret = dp(src, s + 1, dst, p + 1);
                    }
                }
                else
                {
                    if (p + 1 < dst.size() && dst[p + 1] == '*')
                    {
                        // dst[p]匹配0次
                        ret = dp(src, s, dst, p + 2);
                    }
                    else
                    {
                        ret = false;
                    }
                }
                // 记录当前递归的结果
                hash[key] = ret;
                return ret;
            }
        }
    }

public:
    bool isMatch(string s, string p)
    {
        return dp(s, 0, p, 0);
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution s;
    s.isMatch("mississippi", "mis*is*p*.");
    return 0;
}
