/*
 * @lc app=leetcode.cn id=817 lang=cpp
 *
 * [817] 链表组件
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
/**
Accepted
57/57 cases passed (28 ms)
Your runtime beats 83.91 % of cpp submissions
Your memory usage beats 69.56 % of cpp submissions (20.9 MB)
 */
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
    int numComponents(ListNode *head, vector<int> &nums)
    {
        bool isfront = false;
        unordered_set<int> _hash;
        for (auto &num : nums)
        {
            _hash.insert(num);
        }
        int ret = 0;
        ListNode *node = head;
        while (node != nullptr)
        {
            if (_hash.count(node->val) != 0)
            {
                if (isfront == false)
                {
                    ret += 1;
                    isfront = true;
                }
            }
            else
            {
                isfront = false;
            }
            node = node->next;
        }
        return ret;
    }
};
// @lc code=end
