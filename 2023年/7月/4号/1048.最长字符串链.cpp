/*
 * @lc app=leetcode.cn id=1048 lang=cpp
 *
 * [1048] 最长字符串链
 */
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int longestStrChain(vector<string> &words)
    {
        //_hash[word]: word前最长字符串链的长度
        unordered_map<string, int> _hash;
        sort(words.begin(), words.end(), [](const string &left, const string &right)
             { return left.size() < right.size(); });
        int len = 0;
        for (string &word : words)
        {
            _hash[word] = 1;
            for (int i = 0; i < word.size(); i++)
            {
                // 去掉word[i]这个字符
                string prev = word.substr(0, i) + word.substr(i + 1);
                if (_hash.count(prev))
                {
                    _hash[word] = max(_hash[word], _hash[prev] + 1);
                }
            }
            len = max(len, _hash[word]);
        }
        return len;
    }
};
// @lc code=end
