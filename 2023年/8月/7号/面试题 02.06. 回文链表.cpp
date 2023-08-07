/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// 使用递归反向迭代节点，同时使用递归函数外的变量向前迭代，判断链表是否为回文。
#include <iostream>
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution
{
    ListNode *front;
    bool check(ListNode *cur)
    {
        if (cur != nullptr)
        {
            if (!check(cur->next))
            {
                return false;
            }
            if (cur->val != front->val)
            {
                return false;
            }
            front = front->next;
        }
        return true;
    }

public:
    bool isPalindrome(ListNode *head)
    {
        front = head;
        return check(head);
    }
};