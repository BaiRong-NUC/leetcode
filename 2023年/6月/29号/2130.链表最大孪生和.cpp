/*
 * @lc app=leetcode.cn id=2130 lang=cpp
 *
 * [2130] 链表最大孪生和
 */
#include <assert.h>
#include <algorithm>
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
46/46 cases passed (196 ms)
Your runtime beats 62.85 % of cpp submissions
Your memory usage beats 54.14 % of cpp submissions (116 MB)
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
    ListNode *reverse(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        ListNode *next = reverse(head->next);
        head->next->next = head;
        head->next = nullptr;
        return next;
    }

public:
    int pairSum(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head->next;
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
        assert(prev != nullptr);

        ListNode *mid = slow;
        prev->next = nullptr;
        // mid->nullptr翻转
        mid = reverse(mid);

        int ret = 0;
        while (head != nullptr && mid != nullptr)
        {
            ret = std::max(head->val + mid->val, ret);
            head = head->next;
            mid = mid->next;
        }
        return ret;
    }
};
// @lc code=end
