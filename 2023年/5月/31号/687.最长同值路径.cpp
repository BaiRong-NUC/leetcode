/*
 * @lc app=leetcode.cn id=687 lang=cpp
 *
 * [687] 最长同值路径
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
71/71 cases passed (108 ms)
Your runtime beats 87.33 % of cpp submissions
Your memory usage beats 77.76 % of cpp submissions (70 MB)
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
    int ret = 0;
    int dfs(TreeNode *node)
    {
        if (node == nullptr)
            return -1;
        int left = dfs(node->left) + 1;
        int right = dfs(node->right) + 1;

        if (node->left && node->left->val != node->val)
        {
            left = 0;
        }
        if (node->right && node->right->val != node->val)
        {
            right = 0;
        }
        ret = max(ret, left + right);
        return max(left, right);
    }

public:
    int longestUnivaluePath(TreeNode *root)
    {
        dfs(root);
        return ret;
    }
};
// @lc code=end
