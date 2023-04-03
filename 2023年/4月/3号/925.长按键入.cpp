/*
 * @lc app=leetcode.cn id=925 lang=cpp
 *
 * [925] 长按键入
 */

#include <string>
#include <iostream>

using namespace std;

// @lc code=start
class Solution
{
public:
    bool isLongPressedName(string name, string typed)
    {
        int fast = 0;
        int slow = 0;
        while (fast != typed.size() && slow != name.size())
        {
            while (fast != typed.size() && typed[fast] == name[slow])
            {
                fast++;
                slow++;
            }
            if (fast != typed.size())
            {
                if (slow - 1 < 0)
                {
                    return false;
                }
                else
                {
                    while (typed[fast] == name[slow - 1])
                    {
                        fast++;
                    }
                    if (typed[fast] != name[slow])
                    {
                        return false;
                    }
                }
            }
        }
        if (slow == name.size())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
// @lc code=end
