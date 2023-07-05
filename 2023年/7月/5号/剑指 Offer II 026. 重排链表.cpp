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

    void mergeList(ListNode *left, ListNode *right)
    {
        ListNode *left_next = nullptr;
        ListNode *right_next = nullptr;
        while (left != nullptr && right != nullptr)
        {
            left_next = left->next;
            right_next = right->next;

            left->next = right;
            left = left_next;

            right->next = left;
            right = right_next;
        }
    }

public:
    void reorderList(ListNode *head)
    {
        // 链表分成两段
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next;
            if (fast != nullptr)
            {
                fast = fast->next;
            }
        }
        ListNode *mid = slow;
        ListNode *next = mid->next;
        mid->next = nullptr;
        // 后半段逆置
        ListNode *rev = reverse(next);
        // 交替插入
        mergeList(head, rev);
    }
};