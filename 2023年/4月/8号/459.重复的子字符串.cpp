/*
 * @lc app=leetcode.cn id=459 lang=cpp
 *
 * [459] 重复的子字符串
 */
#include <string>
#include <vector>
#include <iostream>
#include <assert.h>
using namespace std;

// @lc code=start
// KMP算法+移动匹配
class Solution
{
    vector<int> next;

    void InitNext(const string &dst, vector<int> &next)
    {
        next[0] = -1;
        next[1] = 0;
        int k = 0;
        for (int i = 2; i < dst.size(); i++)
        {
            while (k != -1 && dst[i - 1] != dst[k])
            {
                k = next[k];
            }
            next[i] = k + 1;
            k += 1;
        }
    }

    int KMP(const string &src, const string &dst, int pos)
    {
        assert(pos >= 0 && pos < src.length() && src.size() > 0 && dst.size() > 0);
        int i = pos;
        int j = 0;
        int srcSize = src.size();
        int dstSize = dst.size();
        vector<int> next(dst.size(), -1);
        InitNext(dst, next);
        while (i < srcSize && j < dstSize)
        {
            if (j == -1 || src[i] == dst[j])
            {
                i++;
                j++;
            }
            else
            {
                j = next[j];
            }
        }
        if (j == dst.size())
        {
            return i - j;
        }
        else
        {
            return -1;
        }
    }

public:
    bool repeatedSubstringPattern(string str)
    {
        if (str.length() <= 1)
        {
            return false;
        }
        else if (str.length() == 2)
        {
            return str[0] == str[1];
        }
        // 思路：s+s去掉开头字符和结尾字符如果仍然出现s，说明s是由重复字符串构成的
        string str_Kmp = str + str;
        str_Kmp = str_Kmp.substr(1, str_Kmp.length() - 2);
        return KMP(str_Kmp, str, 0) != -1;
        // return str_Kmp.find(str) != -1;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution solution;
    cout << solution.repeatedSubstringPattern("abaababaab");
    return 0;
}
