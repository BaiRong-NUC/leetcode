/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
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
    // 一次遍历
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *node = head;
        ListNode *next = node;
        ListNode *prev = nullptr;
        int times = n - 1;
        while (next != nullptr && times > 0)
        {
            next = next->next;
            times--;
        }

        while (next->next != nullptr)
        {
            prev = node;
            node = node->next;
            next = next->next;
        }
        ListNode *del = nullptr;
        if (prev == nullptr)
        {
            // 头删
            del = head;
            head = head->next;
        }
        else
        {
            // 删除node
            del = node;
            prev->next = node->next;
        }
        delete del;
        return head;
    }
};
// @lc code=end
