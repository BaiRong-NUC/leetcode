/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
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

/**
Accepted
95/95 cases passed (24 ms)
Your runtime beats 59.96 % of cpp submissions
Your memory usage beats 53.76 % of cpp submissions (27 MB)
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
    int maxVal = INT_MIN;

public:
    int dfs(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        int left = max(dfs(root->left), 0);
        int right = max(dfs(root->right), 0);

        // 记录最大路径和
        maxVal = max(maxVal, left + right + root->val);

        // 返回最大路径值
        return max(left, right) +
               root->val;
    }

    int maxPathSum(TreeNode *root)
    {
        dfs(root);
        return maxVal;
    }
};
// @lc code=end
