/*
 * @lc app=leetcode.cn id=434 lang=cpp
 *
 * [434] 字符串中的单词数
 */

#include <sstream>
#include <string>
using namespace std;

// @lc code=start
class Solution
{
public:
    int countSegments(string s)
    {
        stringstream stream(s);
        string world;
        int ret = 0;
        while (stream >> world)
        {
            ret += 1;
        }
        return ret;
    }
};
// @lc code=end
