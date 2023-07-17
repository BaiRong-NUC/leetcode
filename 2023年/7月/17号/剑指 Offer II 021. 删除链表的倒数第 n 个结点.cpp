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
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *prev = nullptr;
        ListNode *fast = head;
        ListNode *slow = head;
        for (int i = 0; i < n && fast != nullptr; i++)
        {
            fast = fast->next;
        }
        if (fast == nullptr)
        {
            return head->next;
        }
        while (fast != nullptr)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next;
        }
        prev->next = slow->next;
        return head;
    }
};