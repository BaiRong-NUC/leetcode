/*
 * @lc app=leetcode.cn id=82 lang=cpp
 *
 * [82] 删除排序链表中的重复元素 II
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
#include <iostream>
using namespace std;
/**
Accepted
166/166 cases passed (8 ms)
Your runtime beats 67.32 % of cpp submissions
Your memory usage beats 80.55 % of cpp submissions (10.8 MB)
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
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == nullptr)
        {
            return nullptr;
        }
        ListNode *left = head;
        ListNode *right = head->next;
        ListNode *prev = nullptr;
        while (right != nullptr)
        {
            while (right != nullptr && right->val != left->val)
            {
                prev = left;
                right = right->next;
                left = left->next;
            }
            while (right != nullptr && right->val == left->val)
            {
                right = right->next;
            }
            if (left->next != right)
            {
                if (right != nullptr)
                {
                    if (prev == nullptr)
                    {
                        head = right;
                        left = head;
                    }
                    else
                    {
                        prev->next = right;
                        left = right;
                    }
                    right = right->next;
                }
                else
                {
                    if (prev == nullptr)
                    {
                        head = nullptr;
                    }
                    else
                    {
                        prev->next = nullptr;
                    }
                }
            }
        }
        return head;
    }
};
// @lc code=end
