/*
 * @lc app=leetcode.cn id=725 lang=cpp
 *
 * [725] 分隔链表
 */

#include <vector>
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
43/43 cases passed (8 ms)
Your runtime beats 62.74 % of cpp submissions
Your memory usage beats 18.16 % of cpp submissions (8.7 MB)
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
        int len = 0;
        while (head != nullptr)
        {
            len += 1;
            head = head->next;
        }
        return len;
    }

public:
    vector<ListNode *> splitListToParts(ListNode *head, int k)
    {
        int len = ListSize(head);
        int remain = len % k;
        int group = len / k;
        vector<ListNode *> ret(k, nullptr);
        ListNode *cur = head;
        for (int i = 0; i < k && cur != nullptr; i++)
        {
            ret[i] = cur;
            int part = group + (i < remain ? 1 : 0);
            // std::cout << part << std::endl;
            for (int j = 1; j < part; j++)
            {
                cur = cur->next;
            }
            ListNode *next = cur->next;
            cur->next = nullptr;
            cur = next;
        }
        return ret;
    }
};
// @lc code=end
