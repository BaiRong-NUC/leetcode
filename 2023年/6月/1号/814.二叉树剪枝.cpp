/*
 * @lc app=leetcode.cn id=814 lang=cpp
 *
 * [814] 二叉树剪枝
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

/**
Accepted
31/31 cases passed (4 ms)
Your runtime beats 51.62 % of cpp submissions
Your memory usage beats 85.63 % of cpp submissions (8.5 MB)
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
public:
    TreeNode *pruneTree(TreeNode *root)
    {
        if (root == nullptr)
            return nullptr;
        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);
        if (root->left != nullptr || root->right != nullptr)
        {
            return root;
        }
        return root->val == 0 ? nullptr : root;
    }
};
// @lc code=end
