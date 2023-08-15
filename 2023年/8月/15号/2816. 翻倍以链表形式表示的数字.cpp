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
    ListNode *reverse(ListNode *node)
    {
        if (node == nullptr || node->next == nullptr)
        {
            return node;
        }
        ListNode *next = reverse(node->next);
        node->next->next = node;
        node->next = nullptr;
        return next;
    }

public:
    ListNode *doubleIt(ListNode *head)
    {
        // 链表逆置
        ListNode *rev = reverse(head);
        ListNode *node = rev;
        int carry = 0;
        ListNode *dList = new ListNode(-1);
        ListNode *dTail = dList;
        while (node != nullptr || carry != 0)
        {
            int val = node == nullptr ? carry : (node->val * 2 + carry);
            dTail->next = new ListNode(val % 10);
            dTail = dTail->next;
            carry = val / 10;
            if (node != nullptr)
                node = node->next;
        }
        dList = reverse(dList->next);
        return dList;
    }
};