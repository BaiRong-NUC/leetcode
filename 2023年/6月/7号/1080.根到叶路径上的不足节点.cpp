/*
 * @lc app=leetcode.cn id=1080 lang=cpp
 *
 * [1080] 根到叶路径上的不足节点
 */

#include <iostream>
#include <algorithm>
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
116/116 cases passed (36 ms)
Your runtime beats 85.27 % of cpp submissions
Your memory usage beats 79.12 % of cpp submissions (32.2 MB)
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
public:
    TreeNode *sufficientSubset(TreeNode *root, int limit)
    {
        if (root == nullptr)
            return nullptr;

        // 遍历到叶子节点
        if (root->left == nullptr && root->right == nullptr)
            return root->val < limit ? nullptr : root;

        root->left = sufficientSubset(root->left, limit - root->val);
        root->right = sufficientSubset(root->right, limit - root->val);

        return root->left == nullptr && root->right == nullptr ? nullptr : root;
    }
};
// @lc code=end
