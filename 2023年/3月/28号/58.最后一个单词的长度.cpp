/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 */

#include <iostream>
#include <string>
using namespace std;

// @lc code=start
class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int ret = 0;
        int end = s.length() - 1;
        for (int i = s.length() - 1; i >= 0; i--)
        {
            if (s[i] == ' ')
            {
                end--;
            }
            else
            {
                break;
            }
        }

        for (end; end >= 0; end--)
        {
            if (s[end] == ' ')
            {
                break;
            }
            ret += 1;
        }
        return ret;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution solution;
    string str = "a";
    solution.lengthOfLastWord(str);
    return 0;
}
