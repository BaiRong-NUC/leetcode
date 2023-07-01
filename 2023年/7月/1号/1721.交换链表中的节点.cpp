/*
 * @lc app=leetcode.cn id=1721 lang=cpp
 *
 * [1721] 交换链表中的节点
 */

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
/**
Accepted
132/132 cases passed (500 ms)
Your runtime beats 94.69 % of cpp submissions
Your memory usage beats 60.06 % of cpp submissions (175.9 MB)
 */
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
    void swap(ListNode *&left, ListNode *&right)
    {
        int val = left->val;
        left->val = right->val;
        right->val = val;
    }

public:
    ListNode *swapNodes(ListNode *head, int k)
    {
        ListNode *left = head;
        ListNode *right = head;
        ListNode *cur = head;
        for (int i = 1; i < k && cur->next != nullptr; i++)
        {
            cur = cur->next;
            left = cur;
        }
        cur = head;
        for (int i = 1; i < k && cur->next != nullptr; i++)
        {
            cur = cur->next;
        }
        while (cur->next != nullptr)
        {
            cur = cur->next;
            right = right->next;
        }
        swap(left, right);
        return head;
    }
};
// @lc code=end
