/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

#include <vector>
#include <string>
#include <stack>
#include <iostream>
using namespace std;

/**
Accepted
8/8 cases passed (152 ms)
Your runtime beats 5.11 % of cpp submissions
Your memory usage beats 5 % of cpp submissions (184.9 MB)
 */

// @lc code=start
class Solution
{
    vector<string> ret;
    int len = 0;

    bool isVail(string str)
    {
        stack<char> st;
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] == '(')
            {
                st.push(str[i]);
            }
            else
            {
                if (st.empty())
                {
                    return false;
                }
                st.pop();
            }
        }
        return st.empty();
    }

    void dfs(string &str)
    {
        if (str.length() == len)
        {
            if (isVail(str))
            {
                ret.push_back(str);
            }
            return;
        }
        str += '(';
        dfs(str);
        str.pop_back();
        str += ')';
        dfs(str);
        str.pop_back();
    }

public:
    vector<string> generateParenthesis(int n)
    {
        len = 2 * n;
        string str = "";
        dfs(str);
        return ret;
    }
};
// @lc code=end
