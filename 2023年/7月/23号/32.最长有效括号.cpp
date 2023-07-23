/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 */
#include <string>
#include <stack>
#include <iostream>
using namespace std;
/**
Accepted
231/231 cases passed (0 ms)
Your runtime beats 100 % of cpp submissions
Your memory usage beats 66.4 % of cpp submissions (7.1 MB)
 */
// @lc code=start
class Solution
{
public:
    int longestValidParentheses(string s)
    {
        int ret = 0;
        stack<int> st;
        // 栈中记录的是最近一次没有匹配的下标
        st.push(-1);
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
            {
                st.push(i);
            }
            else
            {
                st.pop();
                if (st.empty())
                {
                    st.push(i);
                }
                else
                {
                    ret = std::max(ret, i - st.top());
                }
            }
        }
        return ret;
    }
};
// @lc code=end
