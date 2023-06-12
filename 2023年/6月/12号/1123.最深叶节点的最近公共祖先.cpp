/*
 * @lc app=leetcode.cn id=1123 lang=cpp
 *
 * [1123] 最深叶节点的最近公共祖先
 */

#include <iostream>
#include <vector>
#include <unordered_map>
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
81/81 cases passed (8 ms)
Your runtime beats 97.12 % of cpp submissions
Your memory usage beats 54.32 % of cpp submissions (20.6 MB)
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
    pair<TreeNode *, int> dfs(TreeNode *root, int deep)
    {
        if (root == nullptr)
            return {root, deep};
        auto [left, deep_left] = dfs(root->left, deep + 1);
        auto [right, deep_right] = dfs(root->right, deep + 1);
        if (deep_left > deep_right)
            return {left, deep_left};
        else if (deep_left < deep_right)
            return {right, deep_right};
        else
            return {root, deep_left};
    }

public:
    TreeNode *lcaDeepestLeaves(TreeNode *root)
    {
        auto [ret, deep] = dfs(root, 0);
        return ret;
    }
};
// @lc code=end
