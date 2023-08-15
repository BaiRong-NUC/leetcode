/*
 * @lc app=leetcode.cn id=2181 lang=cpp
 *
 * [2181] 合并零之间的节点
 */
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
39/39 cases passed (616 ms)
Your runtime beats 42.2 % of cpp submissions
Your memory usage beats 11.32 % of cpp submissions (268.2 MB)
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
    ListNode *mergeNodes(ListNode *head)
    {
        ListNode *List = new ListNode(-1);
        ListNode *Tail = List;
        ListNode *left = head;
        ListNode *right = left->next;
        while (right != nullptr)
        {
            int val = 0;
            while (right->val != 0)
            {
                val += right->val;
                right = right->next;
            }
            Tail->next = new ListNode(val);
            Tail = Tail->next;
            left = right;
            right = right->next;
        }
        return List->next;
    }
};
// @lc code=end
