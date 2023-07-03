/*
 * @lc app=leetcode.cn id=1019 lang=cpp
 *
 * [1019] 链表中的下一个更大节点
 */
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
    vector<int> ret;
    stack<int> st;

    void function(ListNode *head, int pos)
    {
        if (head == nullptr)
        {
            ret.resize(pos, 0);
            return;
        }
        function(head->next, pos + 1);

        while (!st.empty() && st.top() <= head->val)
        {
            st.pop();
        }

        if (!st.empty())
        {
            ret[pos] = st.top();
        }

        st.push(head->val);
    }

public:
    vector<int> nextLargerNodes(ListNode *head)
    {
        function(head, 0);
        return ret;
    }
};
// @lc code=end
