/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */
#include <D:\CppCode\leetcode\global\global.h>
// @lc code=start
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, int> hash;
        int left = 0, right = 0;
        int res = 0;
        while (right < s.size())
        {
            char ch = s[right];
            right += 1;
            hash[ch] += 1;
            // 收缩左窗口
            while (hash[ch] > 1)
            {
                char del = s[left];
                left += 1;
                hash[del] -= 1;
            }
            res = max(res, right - left);
        }
        return res;
    }
};
// @lc code=end
