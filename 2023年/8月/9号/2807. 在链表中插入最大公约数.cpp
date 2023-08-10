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
    // 辗转相除法
    int GetNum(int left, int right)
    {
        return right == 0 ? left : GetNum(right, left % right);
    }

public:
    ListNode *insertGreatestCommonDivisors(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        ListNode *left = head, *right = left->next;
        while (right != nullptr)
        {
            int left_val = left->val;
            int right_val = right->val;
            // 计算最大公约数
            int val = GetNum(left_val, right_val);
            left->next = new ListNode(val);
            left->next->next = right;
            left = right;
            right = right->next;
        }
        return head;
    }
};