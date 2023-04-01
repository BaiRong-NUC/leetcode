/*
 * @lc app=leetcode.cn id=404 lang=cpp
 *
 * [404] 左叶子之和
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
#include <vector>
#include <stack>
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
    void dfs(TreeNode *root, TreeNode *parent, int &ret)
    {
        if (root == nullptr)
        {
            return;
        }
        if (parent == nullptr && root->left == nullptr && root->right == nullptr)
        {
            // 只有根结点
            ret = 0;
            return;
        }
        if (parent != nullptr && parent->left == root && root->left == nullptr && root->right == nullptr)
        {
            ret += root->val;
            return;
        }
        parent = root;
        dfs(root->left, parent, ret);
        dfs(root->right, parent, ret);
    }

public:
    int sumOfLeftLeaves(TreeNode *root)
    {
        int ret = 0;
        dfs(root, nullptr, ret);
        return ret;
    }
};
// @lc code=end
