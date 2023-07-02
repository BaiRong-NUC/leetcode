/*
 * @lc app=leetcode.cn id=2487 lang=cpp
 *
 * [2487] 从链表中移除节点
 */

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
    int max = 0;

public:
    ListNode *removeNodes(ListNode *head)
    {
        if (head->next == nullptr)
        {
            max = head->val;
            return head;
        }
        head->next = removeNodes(head->next);
        if (head->val < max)
        {
            return head->next;
        }
        else
        {
            max = head->val;
            return head;
        }
    }
};
// @lc code=end
