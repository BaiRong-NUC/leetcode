/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
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
30/30 cases passed (196 ms)
Your runtime beats 39.32 % of cpp submissions
Your memory usage beats 31.75 % of cpp submissions (72.3 MB)
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
    ListNode *MergeSort(ListNode *left, ListNode *right)
    {
        ListNode *head = new ListNode(-1);
        ListNode *node = head;
        while (left != nullptr && right != nullptr)
        {
            if (left->val <= right->val)
            {
                node->next = left;
                left = left->next;
            }
            else
            {
                node->next = right;
                right = right->next;
            }
            node = node->next;
        }
        if (left != nullptr)
        {
            node->next = left;
        }
        if (right != nullptr)
        {
            node->next = right;
        }
        return head->next;
    }

    ListNode *Merge(ListNode *head, ListNode *tail)
    {
        if (head == nullptr)
        {
            return nullptr;
        }
        if (head->next == tail)
        {
            head->next = nullptr;
            return head;
        }
        ListNode *slow = head, *fast = head;
        while (fast != tail)
        {
            slow = slow->next;
            fast = fast->next;
            if (fast != tail)
            {
                fast = fast->next;
            }
        }
        ListNode *mid = slow;
        return MergeSort(Merge(head, mid), Merge(mid, tail));
    }

public:
    ListNode *sortList(ListNode *head)
    {
        return Merge(head, nullptr);
    }
};
// @lc code=end
