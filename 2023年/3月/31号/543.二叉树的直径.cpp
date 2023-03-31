/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] 二叉树的直径
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
#include <algorithm>

using namespace std;
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
    int height(TreeNode *node)
    {
        if (node == nullptr)
        {
            return 0;
        }
        int left = height(node->left);
        int right = height(node->right);
        return max(left, right) + 1;
    }

public:
    void dfs(TreeNode *node, int &max)
    {
        if (node == nullptr)
            return;
        int left = height(node->left);
        int right = height(node->right);
        if (max < left + right)
        {
            max = left + right;
        }
        dfs(node->left, max);
        dfs(node->right, max);
    }
    int diameterOfBinaryTree(TreeNode *root)
    {
        int max = 0;
        dfs(root, max);
        return max;
    }
};
// @lc code=end
