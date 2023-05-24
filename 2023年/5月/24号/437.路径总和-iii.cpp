/*
 * @lc app=leetcode.cn id=437 lang=cpp
 *
 * [437] 路径总和 III
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
 *
Accepted
128/128 cases passed (20 ms)
Your runtime beats 64.89 % of cpp submissions
Your memory usage beats 93.17 % of cpp submissions (15.4 MB)
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
    void dfs(TreeNode *root, int targetSum, long val)
    {
        if (root == nullptr)
        {
            return;
        }
        val += root->val;
        if (targetSum == val)
        {
            ret += 1;
        }
        dfs(root->left, targetSum, val);
        dfs(root->right, targetSum, val);
    }

    void coutPath(TreeNode *root, int targetSum)
    {
        if (root == nullptr)
        {
            return;
        }
        dfs(root, targetSum, 0);
        coutPath(root->left, targetSum);
        coutPath(root->right, targetSum);
    }

public:
    int pathSum(TreeNode *root, int targetSum)
    {
        coutPath(root, targetSum);
        return ret;
    }
};
// @lc code=end
