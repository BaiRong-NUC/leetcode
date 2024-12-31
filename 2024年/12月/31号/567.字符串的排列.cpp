/*
 * @lc app=leetcode.cn id=567 lang=cpp
 *
 * [567] 字符串的排列
 */
#include <D:\CppCode\leetcode\global\global.h>
// @lc code=start
class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        // 滑动窗口
        unordered_map<char, int> need, window;
        for (auto &ch : s1)
        {
            need[ch]++;
        }
        int left = 0, right = 0; //[left,right)
        int vaild = 0;           // 判断窗口中是否已经包含了s1中所有字符
        while (right < s2.size())
        {
            // 因为是[left,right)，所ch是将要进入窗口的字符
            char ch = s2[right];
            right += 1;
            if (need.count(ch))
            {
                window[ch] += 1;
                if (window[ch] == need[ch])
                {
                    vaild += 1;
                }
            }
            // 收缩左区间
            if (right - left >= s1.size())
            {
                if (vaild == need.size())
                {
                    return true;
                }
                char ch = s2[left];
                left += 1;
                if (need.count(ch))
                {
                    if (window[ch] == need[ch])
                    {
                        vaild -= 1;
                    }
                    window[ch] -= 1;
                }
            }
        }
        return false;
    }
};
// @lc code=end
