/*
 * @lc app=leetcode.cn id=865 lang=cpp
 *
 * [865] 具有所有最深节点的最小子树
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
Accepted
58/58 cases passed (8 ms)
Your runtime beats 35.36 % of cpp submissions
Your memory usage beats 63.88 % of cpp submissions (14 MB)
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
    TreeNode *ret = nullptr;
    int max_depth = INT_MIN;

    int dfs(TreeNode *root, int depth)
    {
        if (root == nullptr)
            return depth;
        int left = dfs(root->left, depth + 1);
        int right = dfs(root->right, depth + 1);
        int height = max(left, right);

        max_depth = max(max_depth, height);

        if (left == right && max_depth == left)
        {
            ret = root;
        }
        return height;
    }

public:
    TreeNode *subtreeWithAllDeepest(TreeNode *root)
    {
        // 先找最深节点，再找最深节点的公共父亲
        dfs(root, 0);
        return ret;
    }
};
// @lc code=end
