/*
 * @lc app=leetcode.cn id=655 lang=cpp
 *
 * [655] 输出二叉树
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
#include <vector>
#include <string>
#include <iostream>
using namespace std;

/**
Accepted
73/73 cases passed (4 ms)
Your runtime beats 56.25 % of cpp submissions
Your memory usage beats 62.02 % of cpp submissions (8.1 MB)
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
    int deep(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        int left = deep(root->left);
        int right = deep(root->right);
        return max(left, right) + 1;
    }

    void dfs(TreeNode *root, vector<vector<string>> &ret, int row, int col, const int &deep)
    {
        if (root == nullptr)
        {
            return;
        }
        ret[row][col] = to_string(root->val);
        if (root->left != nullptr)
            dfs(root->left, ret, row + 1, col - (1 << (deep - row - 1)), deep);
        if (root->right != nullptr)
            dfs(root->right, ret, row + 1, col + (1 << (deep - row - 1)), deep);
    }

public:
    vector<vector<string>> printTree(TreeNode *root)
    {
        int tree_deep = deep(root) - 1; // 根节点高度为0
        int row = tree_deep + 1;
        int col = (1 << row) - 1;
        vector<vector<string>> ret(row, vector<string>(col, ""));
        dfs(root, ret, 0, (col - 1) / 2, tree_deep);
        return ret;
    }
};
// @lc code=end
