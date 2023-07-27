/*
 * @lc app=leetcode.cn id=389 lang=cpp
 *
 * [389] 找不同
 */
/**
Accepted
54/54 cases passed (0 ms)
Your runtime beats 100 % of cpp submissions
Your memory usage beats 51.75 % of cpp submissions (6.5 MB)
*/
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    char findTheDifference(string s, string t)
    {
        int sum = 0;
        for (int i = 0; i < t.length(); i++)
        {
            sum += t[i];
        }

        for (int i = 0; i < s.length(); i++)
        {
            sum -= s[i];
        }
        return (char)sum;
    }
};
// @lc code=end
