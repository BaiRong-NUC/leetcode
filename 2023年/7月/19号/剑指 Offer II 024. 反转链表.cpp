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
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
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

    ListNode *reverse_display(ListNode *node)
    {
        ListNode *head = new ListNode(-1);
        while (node != nullptr)
        {
            ListNode *next = node->next;
            node->next = head->next;
            head->next = node;
            node = next;
        }
        return head->next;
    }

public:
    ListNode *reverseList(ListNode *head)
    {
        return reverse(head);
    }
};