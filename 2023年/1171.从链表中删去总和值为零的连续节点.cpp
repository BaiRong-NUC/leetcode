/*
 * @lc app=leetcode.cn id=1171 lang=cpp
 *
 * [1171] 从链表中删去总和值为零的连续节点
 */
#include <unordered_map>
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
105/105 cases passed (8 ms)
Your runtime beats 86.83 % of cpp submissions
Your memory usage beats 83.77 % of cpp submissions (10.9 MB)
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
    ListNode *removeZeroSumSublists(ListNode *head)
    {
        unordered_map<int, ListNode *> _hash;
        ListNode *newHead = new ListNode(0);
        newHead->next = head;
        ListNode *node = newHead;
        int val = 0;
        while (node != nullptr)
        {
            val += node->val;
            _hash[val] = node;
            node = node->next;
        }
        val = 0;
        node = newHead;
        while (node != nullptr)
        {
            val += node->val;
            node->next = _hash[val]->next;
            node = node->next;
        }
        return newHead->next;
    }
};
// @lc code=end
