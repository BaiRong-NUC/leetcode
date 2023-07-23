/*
 * @lc app=leetcode.cn id=456 lang=cpp
 *
 * [456] 132 模式
 */
#include <vector>
#include <stack>
#include <iostream>
using namespace std;
/**
Accepted
103/103 cases passed (80 ms)
Your runtime beats 31.12 % of cpp submissions
Your memory usage beats 21.07 % of cpp submissions (47.2 MB)
 */
// @lc code=start
class Solution
{
public:
    bool find132pattern(vector<int> &nums)
    {
        int size = nums.size();
        stack<int> candidate;
        candidate.push(nums[size - 1]);
        int max = INT_MIN; // 记录2数字的最大值
        for (int i = size - 2; i >= 0; i--)
        {
            if (nums[i] < max)
            {
                return true;
            }
            // 将单调栈中，所有小于nums[i]的值全部弹出，并且记录2的最大值
            while (!candidate.empty() && nums[i] > candidate.top())
            {
                max = std::max(max, candidate.top());
                candidate.pop();
            }
            if (nums[i] > max)
            {
                candidate.push(nums[i]);
            }
        }
        return false;
    }
};
// @lc code=end
