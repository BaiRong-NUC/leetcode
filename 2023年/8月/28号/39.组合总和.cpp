/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */
#include <vector>
using namespace std;
/**
Accepted
160/160 cases passed (8 ms)
Your runtime beats 53.15 % of cpp submissions
Your memory usage beats 12.2 % of cpp submissions (16.6 MB)
 */
// @lc code=start
class Solution
{
    void dfs(vector<int> &candidates, int target, vector<vector<int>> &ret, vector<int> &buff, int index)
    {
        if (index == candidates.size())
        {
            return;
        }
        if (target == 0)
        {
            ret.push_back(buff);
            return;
        }
        dfs(candidates, target, ret, buff, index + 1); // 跳过这个位置
        // 选择这个位置
        if (target - candidates[index] >= 0)
        {
            buff.push_back(candidates[index]);
            dfs(candidates, target - candidates[index], ret, buff, index);
            buff.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> ret;
        vector<int> buff;
        dfs(candidates, target, ret, buff, 0);
        return ret;
    }
};
// @lc code=end
