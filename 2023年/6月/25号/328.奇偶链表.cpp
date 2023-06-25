/*
 * @lc app=leetcode.cn id=328 lang=cpp
 *
 * [328] 奇偶链表
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
70/70 cases passed (8 ms)
Your runtime beats 91.46 % of cpp submissions
Your memory usage beats 99.47 % of cpp submissions (10.1 MB)
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
    ListNode *oddEvenList(ListNode *head)
    {
        ListNode *left = new ListNode(-1);
        ListNode *right = new ListNode(-1);
        ListNode *tail_left = left;
        ListNode *tail_right = right;
        ListNode *cur = head;
        bool flag = false;
        while (cur != nullptr)
        {
            ListNode *next = cur->next;
            if (flag == false)
            {
                tail_left->next = cur;
                tail_left = tail_left->next;
                tail_left->next = nullptr;
                flag = true;
            }
            else
            {
                tail_right->next = cur;
                tail_right = tail_right->next;
                tail_right->next = nullptr;
                flag = false;
            }
            cur = next;
        }
        tail_left->next = right->next;
        return left->next;
    }
};
// @lc code=end
