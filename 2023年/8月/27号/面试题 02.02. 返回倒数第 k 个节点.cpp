#include <iostream>
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution
{
public:
    int kthToLast(ListNode *head, int k)
    {
        ListNode *node = head;
        ListNode *tail = node;
        for (int i = 1; i < k; i++)
        {
            // k保证有效
            tail = tail->next;
        }
        while (tail->next != nullptr)
        {
            tail = tail->next;
            node = node->next;
        }
        return node->val;
    }
};