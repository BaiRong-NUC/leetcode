/*
 * @lc app=leetcode.cn id=115 lang=cpp
 *
 * [115] 不同的子序列
 */

#include <string>
#include <map>

using namespace std;

/**
Accepted
65/65 cases passed (28 ms)
Your runtime beats 85.37 % of cpp submissions
Your memory usage beats 73.97 % of cpp submissions (18.6 MB)
 */

// @lc code=start
class Solution
{
    // 记录已经搜索的下标
    map<pair<int, int>, int> _hash;

    int dfs(string &s, string &t, int begins, int begint)
    {
        if (_hash.count({begins, begint}) != 0)
        {
            return _hash[{begins, begint}];
        }
        if (s.size() - begins < t.size() - begint)
        {
            // 无法匹配
            return 0;
        }
        if (begint == t.size())
        {
            return 1;
        }
        // 选择未匹配
        int part = dfs(s, t, begins + 1, begint);
        if (s[begins] == t[begint])
        {
            // 选择匹配
            part += dfs(s, t, begins + 1, begint + 1);
        }
        _hash[{begins, begint}] = part;
        return part;
    }

public:
    int numDistinct(string s, string t)
    {
        return dfs(s, t, 0, 0);
    }
};
// @lc code=end
