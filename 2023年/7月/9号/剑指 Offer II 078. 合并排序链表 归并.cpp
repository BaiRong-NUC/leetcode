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
    ListNode *mergeList(ListNode *left, ListNode *right)
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
    ListNode *merge(vector<ListNode *> &lists, int left, int right)
    {
        if (left == right)
        {
            return lists[left];
        }
        if (left > right)
        {
            return nullptr;
        }
        int mid = (left + right) / 2;
        return mergeList(merge(lists, left, mid), merge(lists, mid + 1, right));
    }

public:
    // 归并合并
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        return merge(lists, 0, lists.size() - 1);
    }
};