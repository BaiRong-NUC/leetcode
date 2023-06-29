/*
 * @lc app=leetcode.cn id=2095 lang=cpp
 *
 * [2095] 删除链表的中间节点
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
70/70 cases passed (972 ms)
Your runtime beats 14.56 % of cpp submissions
Your memory usage beats 67.37 % of cpp submissions (287.8 MB)
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
    ListNode *deleteMiddle(ListNode *head)
    {
        ListNode *fast = head->next;
        ListNode *slow = head;
        ListNode *prev = nullptr;
        while (fast != nullptr)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next;
            if (fast != nullptr)
            {
                fast = fast->next;
            }
        }
        ListNode *mid = slow;
        if (prev == nullptr)
        {
            delete head;
            return nullptr;
        }
        else
        {
            prev->next = mid->next;
            delete mid;
        }
        return head;
    }
};
// @lc code=end
