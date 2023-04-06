/*
 * @lc app=leetcode.cn id=1078 lang=cpp
 *
 * [1078] Bigram 分词
 */

#include <vector>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

// @lc code=start
class Solution
{
    void splitString(string text, vector<string> &buff)
    {
        stringstream strs(text);
        string str;
        while (strs >> str)
        {
            buff.push_back(str);
        }
    }

public:
    vector<string> findOcurrences(string text, string first, string second)
    {
        vector<string> strs;
        vector<string> ret;
        splitString(text, strs);
        int firstIndex = 0;
        int secondIndex = 0;
        while (firstIndex < strs.size())
        {
            while (firstIndex < strs.size() && strs[firstIndex] != first)
            {
                firstIndex++;
            }
            if (firstIndex <= strs.size() && firstIndex >= strs.size() - 2)
            {
                firstIndex = strs.size();
                continue;
            }
            int secondIndex = firstIndex + 1;
            if (strs[secondIndex] != second)
            {
                firstIndex = secondIndex;
                continue;
            }
            // cout<<strs[firstIndex]<<":"<<strs[secondIndex]<<endl;
            ret.push_back(strs[secondIndex + 1]);
            firstIndex = secondIndex;
        }
        return ret;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution solution;
    string text = "ypkk lnlqhmaohv lnlqhmaohv lnlqhmaohv ypkk ypkk ypkk ypkk ypkk ypkk lnlqhmaohv lnlqhmaohv lnlqhmaohv lnlqhmaohv ypkk ypkk ypkk lnlqhmaohv lnlqhmaohv ypkk";
    string first = "lnlqhmaohv";
    string second = "ypkk";
    solution.findOcurrences(text, first, second);
    return 0;
}
