/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
 */
#include <iostream>
using namespace std;
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
231/231 cases passed (8 ms)
Your runtime beats 65.25 % of cpp submissions
Your memory usage beats 79.57 % of cpp submissions (11.3 MB)
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
    int ListSize(ListNode *head)
    {
        int size = 0;
        while (head != nullptr)
        {
            head = head->next;
            size += 1;
        }
        return size;
    }

public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        int size = ListSize(head);
        if (size == 1 || size == 0 || k == 0)
            return head;
        k %= size;
        if (k == 0)
            return head;
        ListNode *right = head;
        ListNode *left = head;
        for (int i = 0; i < k; i++)
        {
            right = right->next;
        }
        while (right->next != nullptr)
        {
            left = left->next;
            right = right->next;
        }
        // left-right之间的节点插入到头节点前
        ListNode *newHead = left->next;
        left->next = nullptr;
        right->next = head;
        head = newHead;
        return head;
    }
};
// @lc code=end
