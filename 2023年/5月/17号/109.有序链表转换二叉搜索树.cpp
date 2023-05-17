/*
 * @lc app=leetcode.cn id=109 lang=cpp
 *
 * [109] 有序链表转换二叉搜索树
 */

/**
Accepted
32/32 cases passed (28 ms)
Your runtime beats 45.3 % of cpp submissions
Your memory usage beats 66.75 % of cpp submissions (27.6 MB)
 */

#include <iostream>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
    // 返回链表的长度
    int length(ListNode *node)
    {
        int ret = 0;
        while (node != nullptr)
        {
            node = node->next;
            ret += 1;
        }
        return ret;
    }

    TreeNode *buildTreeNode(ListNode *&node, int left, int right)
    {
        if (left > right)
        {
            return nullptr;
        }
        int mid = (left + right + 1) / 2;
        TreeNode *root = new TreeNode();
        root->left = buildTreeNode(node, left, mid - 1);
        root->val = node->val;
        node = node->next;
        root->right = buildTreeNode(node, mid + 1, right);
        return root;
    }

public:
    TreeNode *sortedListToBST(ListNode *head)
    {
        int len = length(head);
        return buildTreeNode(head, 0, len - 1);
    }
};
// @lc code=end
