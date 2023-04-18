/*
 * @lc app=leetcode.cn id=717 lang=cpp
 *
 * [717] 1 比特与 2 比特字符
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution
{
public:
    bool isOneBitCharacter(vector<int> &bits)
    {
        int pos = 0;
        while (pos < bits.size() - 1)
        {
            if (bits[pos] == 0)
            {
                pos += 1;
            }
            else if (bits[pos] == 1)
            {
                pos += 2;
            }
        }
        return pos == bits.size() - 1;
    }
};
// @lc code=end
