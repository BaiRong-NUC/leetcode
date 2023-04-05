/*
 * @lc app=leetcode.cn id=1018 lang=cpp
 *
 * [1018] 可被 5 整除的二进制前缀
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// @lc code=start

// 只保留个位数即可判断是否能被5整除，不能直接计算，会溢出
class Solution
{
public:
    vector<bool> prefixesDivBy5(vector<int> &A)
    {
        int temp = 0;
        vector<bool> ans(A.size(), false);
        for (int i = 0; i < A.size(); i++)
        {
            temp = (temp + A[i]) % 10;
            if (temp == 0 || temp == 5)
                ans[i] = true;
            temp *= 2;
        }
        return ans;
    }
};
// class Solution
// {

//     bool GetBool(vector<int> &num, int border)
//     {
//         long long sum = 0;
//         for (int i = border; i >= 0; i--)
//         {
//             sum += num[i] * pow(2, border - i);
//         }
//         return sum % 5 == 0;
//     }

// public:
//     vector<bool> prefixesDivBy5(vector<int> &nums)
//     {
//         vector<bool> ret;
//         for (int i = 0; i < nums.size(); i++)
//         {
//             ret.push_back(GetBool(nums, i));
//         }
//         return ret;
//     }
// };
// @lc code=end
