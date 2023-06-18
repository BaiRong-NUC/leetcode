/*
 * @lc app=leetcode.cn id=143 lang=cpp
 *
 * [143] 重排链表
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
/**
Accepted
12/12 cases passed (40 ms)
Your runtime beats 32.06 % of cpp submissions
Your memory usage beats 99.03 % of cpp submissions (17.2 MB)
*/
class Solution
{
    ListNode *MidList(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode *reverse(ListNode *head)
    {
        ListNode *prev = nullptr;
        ListNode *node = head;
        while (node != nullptr)
        {
            ListNode *next = node->next;
            node->next = prev;
            prev = node;
            node = next;
        }
        return prev;
    }

    void MergeList(ListNode *head, ListNode *rlist)
    {
        ListNode *node = head;
        ListNode *rnode = rlist;
        while (head != nullptr && rlist != nullptr)
        {
            node = head->next;
            rnode = rlist->next;

            head->next = rlist;
            head = node;

            rlist->next = head;
            rlist = rnode;
        }
    }

public:
    void reorderList(ListNode *head)
    {
        // 1.平均切分链表
        ListNode *mid = MidList(head);
        ListNode *right = mid->next;
        mid->next = nullptr;
        // 2. 后半链表逆序
        ListNode *rlist = reverse(right);

        // 3. 两个链表交替合并
        MergeList(head, rlist);
    }
};
// @lc code=end
