/*
 * @lc app=leetcode.cn id=445 lang=cpp
 *
 * [445] 两数相加 II
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
#include <algorithm>
#include <iostream>
using namespace std;
/**
Accepted
1563/1563 cases passed (24 ms)
Your runtime beats 84.42 % of cpp submissions
Your memory usage beats 65.68 % of cpp submissions (69.7 MB)
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
    // 迭代法翻转链表
    ListNode *reverse_display(ListNode *head)
    {
        ListNode *prev = nullptr;
        ListNode *cur = head;
        while (cur != nullptr)
        {
            ListNode *next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }

    // 递归方法翻转链表
    ListNode *reverse(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        ListNode *next = reverse(head->next);
        head->next->next = head;
        head->next = nullptr;
        return next;
    }

    // 遍历法实现链表相加
    ListNode *listAdd_display(ListNode *left, ListNode *right)
    {
        ListNode *head = new ListNode(-1); // 哨兵位
        ListNode *tail = head;
        int flag = 0; // 进位
        while (left != nullptr || right != nullptr)
        {
            int val = (left ? left->val : 0) + (right ? right->val : 0) + flag;
            ListNode *node = new ListNode(val % 10);
            tail->next = node;
            tail = tail->next;
            flag = val / 10;
            if (left != nullptr)
                left = left->next;
            if (right != nullptr)
                right = right->next;
        }
        return head->next;
    }

    // 递归法链表相加
    ListNode *listAdd(ListNode *left, ListNode *right, int flag = 0)
    {
        if (left == nullptr && right == nullptr)
        {
            return flag == 0 ? nullptr : new ListNode(flag);
        }
        if (left == nullptr)
        {
            swap(left, right);
        }
        int val = left->val + (right ? right->val : 0) + flag;
        ListNode *node = new ListNode(val % 10);
        ListNode *next = listAdd(left->next, (right ? right->next : nullptr), val / 10);
        node->next = next;
        return node;
    }

    void PrintList(ListNode *node)
    {
        while (node != nullptr)
        {
            cout << node->val << " ";
            node = node->next;
        }
        cout << endl;
    }

public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        // 链表翻转后，进行链表加和，之后再反转链表
        ListNode *revL1 = reverse_display(l1);
        ListNode *revL2 = reverse(l2);
        // ListNode *ret_rev = listAdd_display(revL1, revL2);
        ListNode *ret_rev = listAdd(revL1, revL2);
        return reverse_display(ret_rev);
    }
};
// @lc code=end
