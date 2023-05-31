/*
 * @lc app=leetcode.cn id=863 lang=cpp
 *
 * [863] 二叉树中所有距离为 K 的结点
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
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
Accepted
57/57 cases passed (8 ms)
Your runtime beats 48.23 % of cpp submissions
Your memory usage beats 67.8 % of cpp submissions (12.5 MB)
 */
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
    unordered_map<TreeNode *, TreeNode *> _hash; // 父节点哈希节点
    vector<int> ret;
    void _init_hash(TreeNode *root)
    {
        if (root == nullptr)
            return;
        if (root->left != nullptr)
            _hash[root->left] = root;
        if (root->right != nullptr)
            _hash[root->right] = root;
        _init_hash(root->left);
        _init_hash(root->right);
    }

    void dfs(TreeNode *root, TreeNode *bef, int depth, int target)
    {
        if (root == nullptr)
            return;
        if (depth == target)
        {
            ret.push_back(root->val);
        }
        if (root->left != bef)
            dfs(root->left, root, depth + 1, target);
        if (root->right != bef)
            dfs(root->right, root, depth + 1, target);
        if (_hash[root] != bef)
            dfs(_hash[root], root, depth + 1, target);
    }

public:
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        _init_hash(root);
        _hash[root] = nullptr;
        dfs(target, nullptr, 0, k);
        return ret;
    }
};
// @lc code=end
