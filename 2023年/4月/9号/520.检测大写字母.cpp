/*
 * @lc app=leetcode.cn id=520 lang=cpp
 *
 * [520] 检测大写字母
 */

#include <string>

using namespace std;

// @lc code=start
class Solution
{
    bool all_small(const string &str, int begin, int end)
    {
        bool ret = true;
        while (begin <= end)
        {
            if (str[begin] >= 65 && str[begin] <= 90)
            {
                ret = false;
            }
            begin += 1;
        }
        return ret;
    }

    bool all_big(const string &str, int begin, int end)
    {
        bool ret = true;
        while (begin <= end)
        {
            if (str[begin] >= 97 && str[begin] <= 122)
            {
                ret = false;
            }
            begin += 1;
        }
        return ret;
    }

public:
    bool detectCapitalUse(string word)
    {
        if (word[0] >= 65 && word[0] <= 90)
        {
            // 大写字母，剩下的字母只能是小写或全部是大写
            return all_big(word, 0, word.length() - 1) || all_small(word, 1, word.length() - 1);
        }
        else
        {
            //  小写字母，剩余字符全部小写
            return all_small(word, 0, word.length() - 1);
        }
    }
};
// @lc code=end
