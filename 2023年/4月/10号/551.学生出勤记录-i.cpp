/*
 * @lc app=leetcode.cn id=551 lang=cpp
 *
 * [551] 学生出勤记录 I
 */

#include <string>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution
{
    bool checkAbsence(string &s)
    {
        unordered_map<char, int> _hash;
        for (int i = 0; i < s.length(); i++)
        {
            _hash[s[i]] += 1;
        }
        return _hash['A'] < 2;
    }

    bool checkLate(string &s)
    {
        int pos = 2;
        int pprev = 0;
        int prev = 1;
        if (s[pprev] == 'L' && s[prev] == 'L' && s[pos] == 'L')
        {
            return false;
        }
        while (pos < s.length())
        {
            if (s[pprev] == 'L' && s[prev] == 'L' && s[pos] == 'L')
            {
                return false;
            }
            prev += 1;
            pprev += 1;
            pos += 1;
        }
        return true;
    }

public:
    bool checkRecord(string s)
    {
        if (s.length() < 3)
        {
            // 不可能出现三次连续迟到
            return checkAbsence(s);
        }
        else
        {
            // 可能出现三次连续迟到
            return checkAbsence(s) && checkLate(s);
        }
    }
};
// @lc code=end
