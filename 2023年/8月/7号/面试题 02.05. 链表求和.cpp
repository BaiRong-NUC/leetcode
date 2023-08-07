#include <iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int carry = 0;
        ListNode *head = new ListNode(-1);
        ListNode *tail = head;
        while (l1 != nullptr || l2 != nullptr || carry != 0)
        {
            int sum = (l1 == nullptr ? 0 : l1->val) + (l2 == nullptr ? 0 : l2->val) + carry;
            carry = sum / 10;
            int val = sum % 10;
            tail->next = new ListNode(val);
            tail = tail->next;
            if (l1 != nullptr)
            {
                l1 = l1->next;
            }
            if (l2 != nullptr)
            {
                l2 = l2->next;
            }
        }
        return head->next;
    }
};