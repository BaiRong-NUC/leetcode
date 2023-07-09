struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

#include <vector>
#include <queue>
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
    struct status
    {
        int val;
        ListNode *node;
        status(ListNode *_node, int _val) : val(_val), node(_node) {}
        bool operator<(const status &right) const
        {
            return val > right.val;
        }
    };

public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        priority_queue<status> q;
        for (auto &list : lists)
        {
            while (list != nullptr)
            {
                q.push(status(list, list->val));
                list = list->next;
            }
        }
        ListNode *head = new ListNode(-1);
        ListNode *tail = head;
        while (!q.empty())
        {
            tail->next = q.top().node;
            q.pop();
            tail = tail->next;
        }
        tail->next = nullptr;
        return head->next;
    }
};