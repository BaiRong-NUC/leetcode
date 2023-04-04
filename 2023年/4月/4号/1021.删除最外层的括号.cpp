/*
 * @lc app=leetcode.cn id=1021 lang=cpp
 *
 * [1021] 删除最外层的括号
 */

#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

// @lc code=start
class Solution
{
public:
    string removeOuterParentheses(string s)
    {
        // 关键核心是拆分字符串
        vector<string> buff;
        stack<char> st;
        string str = "";
        for (int i = 0; i < s.length(); i++)
        {
            str += s[i];
            if (s[i] == '(')
            {
                st.push(s[i]);
            }
            else if (s[i] == ')')
            {
                st.pop();
                if (st.empty())
                {
                    buff.push_back(str);
                    // cout << str << endl;
                    str.clear();
                }
            }
        }
        for (int i = 0; i < buff.size(); i++)
        {
            str += buff[i].substr(1, buff[i].size() - 2);
        }
        return str;
    }
};
// @lc code=end
