/*
 * @lc app=leetcode.cn id=450 lang=cpp
 *
 * [450] 删除二叉搜索树中的节点
 */

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
#include <iostream>
using namespace std;
/**
Accepted
92/92 cases passed (28 ms)
Your runtime beats 88.99 % of cpp submissions
Your memory usage beats 68.37 % of cpp submissions (31.9 MB)
 */
// @lc code=start
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
    void del(TreeNode *&root, int key)
    {
        TreeNode *prev = nullptr;
        TreeNode *node = root;
        while (node != nullptr)
        {
            if (node->val > key)
            {
                prev = node;
                node = node->left;
            }
            else if (node->val < key)
            {
                prev = node;
                node = node->right;
            }
            else
            {
                break;
            }
        }
        if (node != nullptr)
        {
            if (node->left == nullptr && node->right == nullptr)
            {
                // 叶子节点直接删除
                if (prev == nullptr)
                {
                    // 删为空节点
                    delete root;
                    root = nullptr;
                    return;
                }
                prev->left == node ? prev->left = nullptr : prev->right = nullptr;
                delete node;
            }
            else if (node->right == nullptr || node->left == nullptr)
            {
                // 度为1的节点
                if (prev == nullptr)
                {
                    root->left == nullptr ? root = root->right : root = root->left;
                    delete node;
                    return;
                }
                TreeNode *next = nullptr;
                node->left == nullptr ? next = node->right : next = node->left;
                prev->left == node ? prev->left = next : prev->right = next;
                delete node;
            }
            else
            {
                // 非终端节点，替换法删除
                TreeNode *next = node->right;
                while (next->left != nullptr)
                {
                    next = next->left;
                }
                int alt = next->val;
                del(root, alt);
                node->val = alt;
            }
        }
    }

public:
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        del(root, key);
        return root;
    }
};
// @lc code=end
