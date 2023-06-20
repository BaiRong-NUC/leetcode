/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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
55/55 cases passed (0 ms)
Your runtime beats 100 % of cpp submissions
Your memory usage beats 97.57 % of cpp submissions (7.2 MB)
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
public:
    ListNode *swapPairs(ListNode *head)
    {
        if (head == nullptr)
        {
            return nullptr;
        }
        ListNode *left = head;
        ListNode *right = head->next;
        ListNode *node = nullptr;
        ListNode *prev = nullptr;
        while (left != nullptr && right != nullptr)
        {
            left->next = right->next;
            right->next = left;
            if (prev != nullptr)
            {
                prev->next = right;
            }
            prev = left;

            // cout << left->val << ":" << right->val << endl;
            if (node == nullptr)
            {
                node = right;
            }
            left = left->next;
            if (left != nullptr)
            {
                // cout << left->val << endl;
                right = left->next;
            }
        }
        return node == nullptr ? head : node;
    }
};
// @lc code=end
