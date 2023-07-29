/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/**
Accepted
33/33 cases passed (4 ms)
Your runtime beats 94.04 % of cpp submissions
Your memory usage beats 84.12 % of cpp submissions (8.4 MB)
 */
// @lc code=start
class Solution
{
    void display(vector<int> &nums, vector<vector<int>> &ret, int index, vector<int> &buff, vector<bool> &visit)
    {
        if (index == nums.size())
        {
            ret.push_back(buff);
            return;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (visit[i] == true || (i > 0 && nums[i] == nums[i - 1] && !visit[i - 1]))
            {
                continue;
            }
            buff.push_back(nums[i]);
            visit[i] = true;
            display(nums, ret, index + 1, buff, visit);
            buff.pop_back();
            visit[i] = false;
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        vector<vector<int>> ret;
        vector<int> buff;
        vector<bool> visit(nums.size(), false);
        sort(nums.begin(), nums.end());
        display(nums, ret, 0, buff, visit);
        return ret;
    }
};
// @lc code=end
