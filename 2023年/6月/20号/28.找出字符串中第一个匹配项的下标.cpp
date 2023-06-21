/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 找出字符串中第一个匹配项的下标
 */

#include <string>
#include <vector>
#include <iostream>
using namespace std;
// @lc code=start
class Solution
{
    void InitNext(const string &dst, vector<int> &next)
    {
        next[0] = -1;
        next[1] = 0;
        int k = 0;
        for (int i = 2; i < dst.size(); i++)
        {
            k = next[i - 1];
            while (k != -1 && dst[i - 1] != dst[k])
            {
                k = next[k];
            }
            next[i] = k + 1;
        }
    }

public:
    int strStr(string haystack, string needle)
    {
        vector<int> next(needle.size() + 2); // 保证next数组大小
        int srcPos = 0;
        int dstPos = 0;
        InitNext(needle, next);
        while (srcPos < (int)haystack.size() && dstPos < (int)needle.size())
        {
            if (dstPos == -1 || haystack[srcPos] == needle[dstPos])
            {
                srcPos += 1;
                dstPos += 1;
            }
            else
            {
                dstPos = next[dstPos];
            }
        }
        return dstPos == needle.size() ? srcPos - needle.size() : -1;
    }
};
// @lc code=end
