/*
 * @lc app=leetcode.cn id=382 lang=cpp
 *
 * [382] 链表随机节点
 */
#include <stdlib.h>
#include <time.h>
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
8/8 cases passed (24 ms)
Your runtime beats 41.87 % of cpp submissions
Your memory usage beats 71.77 % of cpp submissions (16.1 MB)
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
    ListNode *head = nullptr;

public:
    Solution(ListNode *head)
    {
        this->head = head;
        srand((unsigned int)time(nullptr));
    }

    int getRandom()
    {
        int i = 0;
        int ret = 0;
        ListNode *cur = head;
        while (cur != nullptr)
        {
            i += 1;
            if (rand() % i == 0)
            {
                ret = cur->val;
            }
            cur = cur->next;
        }
        return ret;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
// @lc code=end
