/*
 * @lc app=leetcode.cn id=1669 lang=cpp
 *
 * [1669] 合并两个链表
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
61/61 cases passed (252 ms)
Your runtime beats 67.12 % of cpp submissions
Your memory usage beats 30 % of cpp submissions (92.2 MB)
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
    ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2)
    {
        ListNode *prev = nullptr;
        ListNode *left = list1;
        for (int i = 0; i < a; i++)
        {
            prev = left;
            left = left->next;
        }
        ListNode *right = left;
        for (int i = 0; i < b - a; i++)
        {
            right = right->next;
        }
        if (right != nullptr)
        {
            if (prev == nullptr)
            {
                // 头删
                list1 = right;
            }
            else
            {
                prev->next = list2;
                ListNode *tail = list2;
                while (tail->next != nullptr)
                {
                    tail = tail->next;
                }
                // cout << "DEBUG:" << prev->val << ":" << left->val << ":" << right->val << endl;
                tail->next = right->next;
            }
        }
        return list1;
    }
};
// @lc code=end
