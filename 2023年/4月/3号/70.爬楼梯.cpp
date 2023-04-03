/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

#include <vector>
using namespace std;

// 青蛙跳台阶问题,df数组优化

// @lc code=start
class Solution
{
    vector<int> bf;

public:
    int climbStairs(int n)
    {
        if (n <= 2)
        {
            return n;
        }
        bf.resize(n + 1);
        bf[0] = 0;
        bf[1] = 1;
        bf[2] = 2;
        for (int i = 3; i <= n; i++)
        {
            bf[i] = bf[i - 1] + bf[i - 2];
        }
        return bf[n];
    }
};
// @lc code=end
