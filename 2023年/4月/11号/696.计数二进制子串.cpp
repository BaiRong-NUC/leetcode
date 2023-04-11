/*
 * @lc app=leetcode.cn id=696 lang=cpp
 *
 * [696] 计数二进制子串
 */

/**
    我们可以将字符串s按照0和1的连续段分组，存在counts数组中，例如s =00111011，
    可以得到这样的counts数组: counts= {2,3,1,2}。
    这里counts数组中两个相邻的数一定代表的是两种不同的字符。
    假设counts数组中两个相邻的数字为u或者v，它们对应着u个0和v个1，或者u个1和v个0。
    它们能组成的满足条件的子串数目为min{u,v}，即一对相邻的数字对答案的贡献。
    我们只要遍历所有相邻的数对，求它们的贡献总和，即可得到答案。
 */

#include <string>
#include <vector>
#include <iostream>

using namespace std;

// @lc code=start
class Solution
{
public:
    int countBinarySubstrings(string s)
    {
        vector<int> counts;
        int pos = 0;
        int count = 1;
        while (pos + 1 < s.length())
        {
            if (s[pos] == s[pos + 1])
            {
                count++;
            }
            else
            {
                counts.push_back(count);
                count = 1;
            }
            pos += 1;
        }
        counts.push_back(count);

        int ret = 0;
        // cout << counts.size();
        for (int i = 0; i < counts.size() - 1; i++)
        {
            ret += min(counts[i], counts[i + 1]);
        }
        return ret;
    }
};
// @lc code=end
