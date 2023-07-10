#include <iostream>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
    bool isSearchTree(TreeNode *root, long long min, long long max)
    {
        if (root == nullptr)
        {
            return true;
        }
        if (root->val <= min || root->val >= max)
        {
            return false;
        }
        return isSearchTree(root->left, min, root->val) && isSearchTree(root->right, root->val, max);
    }

public:
    bool isValidBST(TreeNode *root)
    {
        return isSearchTree(root, LONG_MIN, LONG_MAX);
    }
};