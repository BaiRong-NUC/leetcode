/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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
62/62 cases passed (12 ms)
Your runtime beats 87.9 % of cpp submissions
Your memory usage beats 24.3 % of cpp submissions (11.3 MB)
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
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *prev = nullptr;
        ListNode *left = head;
        ListNode *right = head;
        bool newHead = false;
        while (right != nullptr)
        {
            for (int i = 1; i < k && right != nullptr; i++)
            {
                right = right->next;
            }
            if (newHead == false)
            {
                newHead = true;
                head = right;
            }
            if (right != nullptr)
            {
                // 翻转left->right
                ListNode *next = right->next;
                right->next = nullptr;
                ListNode *rev = reverse(left);

                if (prev == nullptr)
                {
                    prev = left;
                }
                else
                {
                    prev->next = right;
                    prev = left;
                }
                left = next;
                right = next;
            }
            else
            {
                if (prev != nullptr)
                {
                    prev->next = left;
                }
                else
                {
                    return head;
                }
            }
        }
        return head;
    }
};
// @lc code=end
