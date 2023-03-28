/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */
#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;
// @lc code=start
class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        unordered_map<char, int> hash;
        string ret = "";
        size_t del = 0;
        bool flag = true;
        while (flag)
        {
            for (int i = 0; i < strs.size(); i++)
            {
                int len = strs[i].length();
                if (i == 0)
                {
                    if (del == len)
                    {
                        flag = false;
                        break;
                    }
                    else
                    {
                        hash.insert(make_pair(strs[i][del], 1));
                        // cout << strs[i][del] << " ";
                        continue;
                    }
                }
                if ((del == len) || (hash.find(strs[i][del]) == hash.end()))
                {
                    // 没有匹配
                    flag = false;
                    break;
                }
            }
            if (flag == true)
            {
                ret.push_back(strs[0][del]);
            }
            hash.clear();
            del += 1;
        }
        return ret;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<string> strs = {"abca", "aba", "aaab"};
    cout << strs.size() << endl;
    solution.longestCommonPrefix(strs);
    return 0;
}
