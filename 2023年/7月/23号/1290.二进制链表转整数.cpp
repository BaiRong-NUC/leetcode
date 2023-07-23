/*
 * @lc app=leetcode.cn id=1290 lang=cpp
 *
 * [1290] 二进制链表转整数
 */
/**
Accepted
102/102 cases passed (0 ms)
Your runtime beats 100 % of cpp submissions
Your memory usage beats 63.9 % of cpp submissions (8 MB)
*/
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
    int getDecimalValue(ListNode *head)
    {
        int ret = 0;
        ListNode *node = head;
        while (node != nullptr)
        {
            ret = ret * 2 + node->val;
            node = node->next;
        }
        return ret;
    }
};
// @lc code=end
