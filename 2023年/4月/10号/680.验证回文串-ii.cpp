/*
 * @lc app=leetcode.cn id=680 lang=cpp
 *
 * [680] 验证回文串 II
 */

#include <string>

using namespace std;

// @lc code=start
class Solution
{
    bool _del = false;
    // 判断s从begin-end是不是回文字符串
    bool isAvail(string s, int begin, int end)
    {
        while (begin < end)
        {
            if (s[begin] != s[end])
            {
                if (_del == false)
                {
                    _del = true;
                    return isAvail(s, begin + 1, end) || isAvail(s, begin, end - 1);
                }
                else
                {
                    return false;
                }
            }
            begin += 1;
            end -= 1;
        }
        return true;
    }

public:
    bool validPalindrome(string s)
    {
        return isAvail(s, 0, s.length() - 1);
    }
};
// @lc code=end
