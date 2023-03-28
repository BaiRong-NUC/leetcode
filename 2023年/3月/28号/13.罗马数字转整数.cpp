/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */
#include <string>
#include <unordered_map>
#include <cmath>

using namespace std;

// @lc code=start
class Solution
{
private:
    unordered_map<char, int> hash;

public:
    Solution()
    {
        hash.insert(make_pair('I', 1));
        hash.insert(make_pair('V', 5));
        hash.insert(make_pair('X', 10));
        hash.insert(make_pair('L', 50));
        hash.insert(make_pair('C', 100));
        hash.insert(make_pair('D', 500));
        hash.insert(make_pair('M', 1000));
    }

    int romanToInt(string s)
    {
        int ret = 0;
        int flag = 2; // 记录下一次的操作是+还是-
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == 'I' || s[i] == 'X' || s[i] == 'C')
            {
                if (i + 1 < s.length())
                {
                    // 检查后面一个字符
                    if (s[i] == 'I' && (s[i + 1] == 'V' || s[i + 1] == 'X'))
                    {
                        flag = 1;
                    }
                    else if (s[i] == 'X' && (s[i + 1] == 'L' || s[i + 1] == 'C'))
                    {
                        flag = 1;
                    }
                    else if (s[i] == 'C' && (s[i + 1] == 'D' || s[i + 1] == 'M'))
                    {
                        flag = 1;
                    }
                }
            }
            ret += pow(-1, flag) * hash[s[i]];
            flag = 2; // 默认下一次是+
        }
        return ret;
    }
};
// @lc code=end
