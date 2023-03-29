/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根
 */

#include <algorithm>
#include <iostream>

using namespace std;

// @lc code=start
class Solution
{
public:
    int mySqrt(int x)
    {
        int l = 0, r = x, ans = -1;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if ((long long)mid * mid <= x)
            {
                ans = mid;
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution s;
    s.mySqrt(4);
    return 0;
}
