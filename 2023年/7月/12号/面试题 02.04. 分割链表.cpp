/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <iostream>
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *partition(ListNode *head, int x)
    {
        ListNode *maxList = new ListNode(-1);
        ListNode *tail = maxList;
        ListNode *node = head;
        ListNode *prev = nullptr;
        while (node != nullptr)
        {
            if (node->val >= x)
            {
                if (prev == nullptr)
                {
                    tail->next = head;
                    head = head->next;
                }
                else
                {
                    prev->next = node->next;
                    tail->next = node;
                }
                node = node->next;
                tail = tail->next;
                tail->next = nullptr;
            }
            else
            {
                prev = node;
                node = node->next;
            }
        }
        if (prev != nullptr)
            prev->next = maxList->next;
        else
            head = maxList->next;
        return head;
    }
};