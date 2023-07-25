/*
 * @lc app=leetcode.cn id=229 lang=cpp
 *
 * [229] 多数元素 II
 */
#include <vector>
#include <unordered_map>
using namespace std;
/**
Accepted
87/87 cases passed (24 ms)
Your runtime beats 10.32 % of cpp submissions
Your memory usage beats 5.21 % of cpp submissions (15.7 MB)
 */
// @lc code=start
class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        // 哈希表统计出现次数
        unordered_map<int, int> _hash;
        int size = nums.size();
        for (int i = 0; i < size; i++)
        {
            _hash[nums[i]] += 1;
        }
        vector<int> ret;
        for (auto &ptr : _hash)
        {
            if (ptr.second > size / 3)
            {
                ret.push_back(ptr.first);
            }
        }
        return ret;
    }
};
// @lc code=end
