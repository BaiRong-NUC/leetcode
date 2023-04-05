/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 */

#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution
{
    unordered_map<int, int> _hash;

public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        for (int i = 0; i < nums1.size(); i++)
        {
            if (_hash.find(nums1[i]) != _hash.end())
            {
                nums1[i]++;
            }
            else
            {
                pair<int, int> elem(nums1[i], 0);
                _hash.insert(elem);
            }
        }
        vector<int> ret;
        for (int i = 0; i < nums2.size(); i++)
        {
            if ((_hash.find(nums2[i]) != _hash.end()) && find(ret.begin(), ret.end(), nums2[i]) == ret.end())
            {
                ret.push_back(nums2[i]);
            }
        }
        return ret;
    }
};
// @lc code=end
