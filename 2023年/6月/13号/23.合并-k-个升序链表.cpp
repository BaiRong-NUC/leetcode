/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并 K 个升序链表
 */
#include <iostream>
#include <vector>
#include <queue>
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
133/133 cases passed (32 ms)
Your runtime beats 35.83 % of cpp submissions
Your memory usage beats 25.58 % of cpp submissions (13.3 MB)
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
    struct Date
    {
        int val;
        ListNode *head;
        // 当前一个数比后一个数大时交换，最后从小到大排列
        bool operator<(const Date &other) const
        {
            return val > other.val;
        }
    };

public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        priority_queue<Date> q;
        for (ListNode *node : lists)
        {
            if (node != nullptr)
                q.push({node->val, node});
        }
        ListNode *head = new ListNode(-1);
        ListNode *tail = head;
        while (!q.empty())
        {
            Date node = q.top();
            q.pop();
            tail->next = node.head;
            tail = tail->next;
            if (node.head->next != nullptr)
            {
                q.push({node.head->next->val, node.head->next});
            }
        }
        return head->next;
    }
};
// @lc code=end
