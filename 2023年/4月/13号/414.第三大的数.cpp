/*
 * @lc app=leetcode.cn id=414 lang=cpp
 *
 * [414] 第三大的数
 */

#include <vector>
#include <queue>
#include <algorithm>
#include <set> //去重

using namespace std;

/**
Accepted
34/34 cases passed (8 ms)
Your runtime beats 52.51 % of cpp submissions
Your memory usage beats 6.73 % of cpp submissions (10.5 MB)
 */

// @lc code=start
class Solution
{
public:
    int thirdMax(vector<int> &nums)
    {
        set<int> _set;
        priority_queue<int, vector<int>, greater<int>> queue;
        for (int i = 0; i < nums.size(); i++)
        {
            _set.insert(nums[i]);
        }

        for (auto i = _set.begin(); i != _set.end(); i++)
        {
            if (queue.size() < 3)
            {
                queue.push(*i);
            }
            else
            {
                if (*i > queue.top())
                {
                    queue.pop();
                    queue.push(*i);
                }
            }
        }
        if (queue.size() < 3)
        {
            return *max_element(nums.begin(), nums.end());
        }
        return queue.top();
    }
};
// @lc code=end
