/*
 * @lc app=leetcode.cn id=951 lang=cpp
 *
 * [951] 翻转等价二叉树
 */

#include <string>
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
77/77 cases passed (0 ms)
Your runtime beats 100 % of cpp submissions
Your memory usage beats 47.27 % of cpp submissions (11.9 MB)
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
    void dfs(TreeNode *root, string &msg)
    {
        if (root == nullptr)
        {
            msg += "#";
            return;
        }
        msg += to_string(root->val);
        int left = root->left == nullptr ? -1 : root->left->val;
        int right = root->right == nullptr ? -1 : root->right->val;

        // 标准化递归
        if (left > right)
        {
            dfs(root->right, msg);
            dfs(root->left, msg);
        }
        else
        {
            dfs(root->left, msg);
            dfs(root->right, msg);
        }
    }

public:
    bool flipEquiv(TreeNode *root1, TreeNode *root2)
    {
        // 标准态遍历
        string msg_root1 = "";
        dfs(root1, msg_root1);
        string msg_root2 = "";
        dfs(root2, msg_root2);
        return msg_root1 == msg_root2;
    }
};
// @lc code=end
