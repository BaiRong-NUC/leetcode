/*
 * @lc app=leetcode.cn id=129 lang=cpp
 *
 * [129] 求根节点到叶节点数字之和
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
108/108 cases passed (0 ms)
Your runtime beats 100 % of cpp submissions
Your memory usage beats 78.82 % of cpp submissions (8.9 MB)
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
    void dfs(TreeNode *node, int &ret, string path)
    {
        if (node == nullptr)
            return;
        if (node->left == nullptr && node->right == nullptr)
        {
            path += node->val + '0';
            ret += atoi(path.c_str());
            path.pop_back();
            return;
        }
        path += node->val + '0';
        dfs(node->left, ret, path);
        dfs(node->right, ret, path);
    }

public:
    int sumNumbers(TreeNode *root)
    {
        int ret = 0;
        string path;
        dfs(root, ret, path);
        return ret;
    }
};
// @lc code=end
