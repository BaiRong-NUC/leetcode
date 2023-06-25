/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
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
    ListNode *last = nullptr;
    ListNode *reverse(ListNode *head, int right)
    {
        if (right == 1)
        {
            last = head->next;
            return head;
        }
        ListNode *rev = reverse(head->next, right - 1);

        head->next->next = head;
        head->next = last;
        return rev;
    }

public:
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        if (left == 1)
        {
            return reverse(head, right);
        }
        else
        {
            head->next = reverseBetween(head->next, left - 1, right - 1);
        }
        return head;
    }
};
// @lc code=end
