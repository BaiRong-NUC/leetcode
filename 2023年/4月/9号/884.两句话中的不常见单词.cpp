/*
 * @lc app=leetcode.cn id=884 lang=cpp
 *
 * [884] 两句话中的不常见单词
 */

#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution
{
    void SplitWords(string &str, vector<string> &vet)
    {
        vet.clear();
        int left = 0;
        int right = 0;
        while (left < str.length() && str[left] == ' ')
        {
            left += 1;
            right += 1;
        }
        while (left < str.length() && right < str.length())
        {
            while (right < str.length() && str[right] != ' ')
            {
                right++;
            }
            vet.push_back(str.substr(left, right - left));
            right++;
            left = right;
        }
    }

public:
    vector<string> uncommonFromSentences(string s1, string s2)
    {
        vector<string> words;
        string str = s1 + " " + s2;
        SplitWords(str, words);

        unordered_map<string, int> _hash;
        for (int i = 0; i < words.size(); i++)
        {
            _hash[words[i]] += 1;
        }

        vector<string> ret;

        for (auto it = _hash.begin(); it != _hash.end(); it++)
        {
            if (it->second == 1)
            {
                ret.push_back(it->first);
            }
        }

        return ret;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution solution;
    solution.uncommonFromSentences("this apple is sweet", "this apple is Up");
    return 0;
}
