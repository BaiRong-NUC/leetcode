/*
 * @lc app=leetcode.cn id=237 lang=cpp
 *
 * [237] 删除链表中的节点
 */
#include <iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
/**
Accepted
41/41 cases passed (4 ms)
Your runtime beats 99.22 % of cpp submissions
Your memory usage beats 77.64 % of cpp submissions (7.4 MB)
 */
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    void deleteNode(ListNode *node)
    {
        int val = node->val;
        node->val = node->next->val;
        node->next->val = val;
        ListNode *next = node->next->next;
        delete node->next;
        node->next = next;
    }
};
// @lc code=end
