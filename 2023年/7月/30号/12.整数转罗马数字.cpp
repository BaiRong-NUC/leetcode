/*
 * @lc app=leetcode.cn id=12 lang=cpp
 *
 * [12] 整数转罗马数字
 */
#include <string>
#include <vector>
using namespace std;
/**
Accepted
3999/3999 cases passed (12 ms)
Your runtime beats 27.23 % of cpp submissions
Your memory usage beats 16.7 % of cpp submissions (9.1 MB)
 */
// @lc code=start
class Solution
{
    vector<pair<int, string>> value = {
        {1000, "M"},
        {900, "CM"},
        {500, "D"},
        {400, "CD"},
        {100, "C"},
        {90, "XC"},
        {50, "L"},
        {40, "XL"},
        {10, "X"},
        {9, "IX"},
        {5, "V"},
        {4, "IV"},
        {1, "I"},
    };

public:
    string intToRoman(int num)
    {
        string roman;
        for (const auto &[value, str] : value)
        {
            while (num >= value)
            {
                num -= value;
                roman += str;
            }
            if (num == 0)
            {
                break;
            }
        }
        return roman;
    }
};
// @lc code=end
