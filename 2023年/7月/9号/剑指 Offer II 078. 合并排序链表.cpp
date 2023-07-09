struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

#include <vector>
using namespace std;

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
    ListNode *merge(ListNode *left, ListNode *right)
    {
        if (left == nullptr || right == nullptr)
        {
            return left == nullptr ? right : left;
        }

        ListNode *head = new ListNode(-1);
        ListNode *tail = head;
        while (left != nullptr && right != nullptr)
        {
            if (left->val <= right->val)
            {
                tail->next = left;
                left = left->next;
            }
            else
            {
                tail->next = right;
                right = right->next;
            }
            tail = tail->next;
        }
        if (left != nullptr)
        {
            tail->next = left;
        }
        if (right != nullptr)
        {
            tail->next = right;
        }
        ListNode *ret = head->next;
        delete head;
        return ret;
    }

public:
    // 顺序合并法,多次调用合并两个链表函数
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        ListNode *head = nullptr;
        for (int i = 0; i < lists.size(); i++)
        {
            head = merge(head, lists[i]);
        }
        return head;
    }
};