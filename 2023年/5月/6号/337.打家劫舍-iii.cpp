/*
 * @lc app=leetcode.cn id=337 lang=cpp
 *
 * [337] 打家劫舍 III
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
#include <unordered_map>
using namespace std;

/**
Accepted
124/124 cases passed (24 ms)
Your runtime beats 47.95 % of cpp submissions
Your memory usage beats 52.61 % of cpp submissions (28.1 MB)
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
    unordered_map<TreeNode *, int> check, uncheck;

    void dfs(TreeNode *root)
    {
        if (root == nullptr)
            return;
        dfs(root->left);
        dfs(root->right);
        // 选择root,root的孩子无法选择
        check[root] = uncheck[root->left] + uncheck[root->right] + root->val;
        // 不选择root,可以选择左子树，或不选择，可以选择右子树或不选择
        uncheck[root] = max(check[root->left], uncheck[root->left]) + max(check[root->right], uncheck[root->right]);
    }

public:
    int rob(TreeNode *root)
    {
        // 二叉树层序遍历+DP即可,因为要从叶节点遍历到根节点，这里选择后序遍历
        dfs(root);
        return max(check[root], uncheck[root]);
    }
};
// @lc code=end
