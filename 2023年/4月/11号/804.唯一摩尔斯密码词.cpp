/*
 * @lc app=leetcode.cn id=804 lang=cpp
 *
 * [804] 唯一摩尔斯密码词
 */

/**
 * @file 804.唯一摩尔斯密码词.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-04-11
 * Accepted
 * 82/82 cases passed (12 ms)
 * Your runtime beats 0.49 % of cpp submissions
 * Your memory usage beats 5.17 % of cpp submissions (8.8 MB)
 * @copyright Copyright (c) 2023
 *
 */

#include <string>
#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;

// @lc code=start
class Solution
{
    vector<string> _code =
        {".-", "-...", "-.-.",
         "-..", ".", "..-.",
         "--.", "....", "..",
         ".---", "-.-", ".-..",
         "--", "-.", "---",
         ".--.", "--.-", ".-.",
         "...", "-", "..-",
         "...-", ".--", "-..-",
         "-.--", "--.."};

public:
    int uniqueMorseRepresentations(vector<string> &words)
    {
        unordered_map<string, string> encode;
        for (int i = 0; i < words.size(); i++)
        {
            string code = "";
            for (int j = 0; j < words[i].size(); j++)
            {
                code += _code[words[i][j] - 'a'];
            }
            encode.insert({code, words[i]});
        }
        return encode.size();
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    vector<string> words = {"gin", "zen", "gig", "msg"};
    Solution solution;
    solution.uniqueMorseRepresentations(words);
    return 0;
}
