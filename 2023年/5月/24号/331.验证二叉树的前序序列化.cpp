/*
 * @lc app=leetcode.cn id=331 lang=cpp
 *
 * [331] 验证二叉树的前序序列化
 */
#include <string>
#include <stack>
using namespace std;

/**
Accepted
152/152 cases passed (4 ms)
Your runtime beats 69.41 % of cpp submissions
Your memory usage beats 55.42 % of cpp submissions (6.7 MB)
 */
// @lc code=start
class Solution
{
    int begin = 0;
    int end = 0;

public:
    bool isValidSerialization(string preorder)
    {
        // 使用栈来判断前序遍历的空槽是否够用
        stack<int> st;
        st.push(1);
        int i = 0;
        while (i < preorder.size())
        {
            if (st.empty())
            {
                return false;
            }
            if (preorder[i] == ',')
            {
                i++;
            }
            else if (preorder[i] == '#')
            {
                st.top() -= 1;
                if (st.top() == 0)
                {
                    st.pop();
                }
                i++;
            }
            else
            {
                // 读取数字
                while (i < preorder.size() && preorder[i] != ',')
                {
                    i += 1;
                }
                st.top() -= 1;
                if (st.top() == 0)
                {
                    st.pop();
                }
                st.push(2);
            }
        }
        return st.empty();
    }
};
// @lc code=end
