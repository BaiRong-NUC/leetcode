/*
 * @lc app=leetcode.cn id=345 lang=cpp
 *
 * [345] 反转字符串中的元音字母
 */

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution
{
    vector<char> target = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

public:
    string reverseVowels(string s)
    {
        int left = 0;
        int right = s.length() - 1;
        while (left <= right)
        {
            while (right >= left && find(target.begin(), target.end(), s[right]) == target.end())
            {
                right -= 1;
            }
            while (left <= right && find(target.begin(), target.end(), s[left]) == target.end())
            {
                left += 1;
            }
            if (right >= left)
            {
                swap(s[left], s[right]);
            }
            left += 1;
            right -= 1;
        }
        return s;
    }
};
// @lc code=end
