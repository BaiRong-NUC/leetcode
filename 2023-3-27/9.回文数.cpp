/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

#include <iostream>

using namespace std;

// @lc code=start
class Solution
{
public:
    bool isPalindrome(int x)
    {
        string str = std::to_string(x);
        int left = 0;
        int right = str.length() - 1;
        while (left < right)
        {
            if (str[left] != str[right])
            {
                // cout << str[left] << " " << str[right] << endl;
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};
// @lc code=end
