/*
 * @lc app=leetcode.cn id=1009 lang=cpp
 *
 * [1009] 十进制整数的反码
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// @lc code=start
class Solution
{
public:
    int bitwiseComplement(int n)
    {
        if (n == 0)
        {
            return 1;
        }
        vector<int> binaryNum; // 将n转化为二进制
        while (n != 0)
        {
            binaryNum.push_back((n % 2) ^ 1); // 直接插入反码
            n /= 2;
        }
        // std::reverse(binaryNum.begin(), binaryNum.end());
        int ret = 0;
        for (int i = 0; i < binaryNum.size(); i++)
        {
            ret += binaryNum[i] * pow(2, i);
        }
        return ret;
    }
};
// @lc code=end
