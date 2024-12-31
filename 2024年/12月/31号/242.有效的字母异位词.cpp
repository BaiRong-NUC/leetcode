/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */
#include <D:\CppCode\leetcode\global\global.h>
// @lc code=start
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        unordered_map<char, int> need, window;
        if (s.length() != t.length())
            return false;
        
        for (char c : s)
            need[c]++;
        int left = 0, right = 0;
        int valid = 0;
        while (right < t.size())
        {
            char ch = t[right];
            right += 1;
            if (need.count(ch))
            {
                window[ch]++;
                if (window[ch] == need[ch])
                {
                    valid++;
                }
            }
            // 判断左侧窗口是否要收缩
            while (right - left >= s.size())
            {
                if (valid == need.size())
                {
                    return true;
                }
                // s与t长度相同，当right - left第一次与s.length相等时如果不匹配直接返回错误
                return false;
            }
        }
        return false;
    }
};
// @lc code=end