/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        digits[digits.size() - 1] += 1;
        int del = digits.size() - 1;
        while (digits[del] >= 10)
        {
            digits[del] -= 10;
            if (del - 1 >= 0)
            {
                digits[del - 1] += 1;
            }
            else
            {
                // 头插1后退出循环
                digits.insert(digits.begin(), 1);
                break;
            }
            del--;
        }
        return digits;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    vector<int> ret = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    Solution solution;
    solution.plusOne(ret);
    return 0;
}
