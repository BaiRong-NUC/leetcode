/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
 */
#include <D:\CppCode\leetcode\global\global.h>
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (fast == slow)
            {
                // 带环相遇时 fast走2nb slow走nb(n=1,2,3..)
                // 当节点从头开始走a+nb时，节点在环的入口处，slow已经走了nb了，只要再让其走a个即可
                //  此时让fast从头节点开始走，slow继续走，相遇时即为环的入口
                fast = head;
                while (fast != slow)
                {
                    fast = fast->next;
                    slow = slow->next;
                }
                return slow; // slow走了a+nb次，一定在环入口处相遇
            }
        }
        // 不带环
        return nullptr;
    }
};
// @lc code=end
