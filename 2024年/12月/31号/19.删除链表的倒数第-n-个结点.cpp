/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
 */
#include <D:\CppCode\leetcode\global\global.h>
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
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        // 快慢指针
        ListNode *fast = head;
        ListNode *slow = head;
        ListNode *prev = nullptr;
        for (int i = 0; i < n; i++)
        {
            fast = fast->next;
        }
        while (fast != nullptr)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next;
        }
        // 删除slow节点
        if (prev == nullptr)
        {
            // 头删
            head = head->next;
        }
        else
        {
            prev->next = slow->next;
        }
        // delete(slow);
        return head;
    }
};
// @lc code=end