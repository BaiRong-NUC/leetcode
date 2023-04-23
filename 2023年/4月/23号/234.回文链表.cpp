/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
 */

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
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
public:
    bool isPalindrome(ListNode *head)
    {
        vector<int> ret;
        ListNode *node = head;
        while (node != nullptr)
        {
            ret.push_back(node->val);
            node = node->next;
        }
        vector<int> copy(ret);
    std:
        reverse(ret.begin(), ret.end());
        for (int i = 0; i < ret.size(); i++)
        {
            if (ret[i] != copy[i])
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
