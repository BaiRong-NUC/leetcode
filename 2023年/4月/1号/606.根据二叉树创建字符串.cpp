/*
 * @lc app=leetcode.cn id=606 lang=cpp
 *
 * [606] 根据二叉树创建字符串
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
    string dfs(TreeNode *node, TreeNode *parent)
    {
        if (node == nullptr)
        {
            if (parent->left == nullptr)
            {
                return "()";
            }
            if (parent->right == nullptr)
            {
                return "";
            }
        }
        if (node->left == nullptr && node->right == nullptr)
        {
            return "(" + to_string(node->val) + ")";
        }
        parent = node;
        string ret_left = dfs(node->left, parent);
        string ret_right = dfs(node->right, parent);
        string ret = to_string(node->val);
        return "(" + ret + ret_left + ret_right + ")";
    }

public:
    string tree2str(TreeNode *root)
    {
        string ret = "";
        ret = dfs(root, nullptr);
        return ret.substr(1, ret.length() - 2);
    }
};
// @lc code=end
