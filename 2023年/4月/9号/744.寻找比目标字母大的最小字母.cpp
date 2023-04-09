/*
 * @lc app=leetcode.cn id=744 lang=cpp
 *
 * [744] 寻找比目标字母大的最小字母
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution
{
public:
    char nextGreatestLetter(vector<char> &letters, char target)
    {
        char ret = letters[0];
        for (int i = 0; i < letters.size(); i++)
        {
            if (letters[i] > target)
            {
                ret = letters[i];
                break;
            }
        }
        return ret;
    }
};
// @lc code=end
