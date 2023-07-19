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
#include <stack>
using namespace std;
class Solution
{
    // 进阶，不使用反转链表
    void insert(ListNode *head, int val)
    {
        ListNode *node = new ListNode(val);
        node->next = head->next;
        head->next = node;
    }

public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        stack<int> st1;
        stack<int> st2;
        while (l1 != nullptr)
        {
            st1.push(l1->val);
            l1 = l1->next;
        }
        while (l2 != nullptr)
        {
            st2.push(l2->val);
            l2 = l2->next;
        }
        // cout<<st1.size()<<":"<<st2.size()<<endl;
        ListNode *head = new ListNode(-1);
        int carry = 0;
        while (!st1.empty() && !st2.empty())
        {
            int val = st1.top() + st2.top() + carry;
            carry = val / 10;
            val = val % 10;
            st1.pop();
            st2.pop();
            insert(head, val);
        }
        while (!st1.empty())
        {
            int val = st1.top() + carry;
            carry = val / 10;
            val = val % 10;
            st1.pop();
            insert(head, val);
        }
        while (!st2.empty())
        {
            int val = st2.top() + carry;
            carry = val / 10;
            val = val % 10;
            st2.pop();
            insert(head, val);
        }
        if (carry != 0)
        {
            insert(head, carry);
        }
        return head->next;
    }
};