/*
 * @lc app=leetcode.cn id=941 lang=cpp
 *
 * [941] 有效的山脉数组
 */

#include <vector>
#include <algorithm>

using namespace std;

/**
Accepted
53/53 cases passed (20 ms)
Your runtime beats 86.23 % of cpp submissions
Your memory usage beats 25.3 % of cpp submissions (21.9 MB)
 */

// @lc code=start
class Solution
{
public:
    bool validMountainArray(vector<int> &arr)
    {
        int max = *max_element(arr.begin(), arr.end());
        int pos = find(arr.begin(), arr.end(), max) - arr.begin();
        if (pos == 0 || pos == arr.size() - 1)
        {
            return false;
        }
        for (int i = 0; i < pos; i++)
        {
            if (arr[i] - arr[i + 1] >= 0)
            {
                return false;
            }
        }
        for (int i = pos; i < arr.size() - 1; i++)
        {
            if (arr[i] - arr[i + 1] <= 0)
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
