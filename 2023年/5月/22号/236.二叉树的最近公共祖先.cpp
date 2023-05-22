/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
 */
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
/**
Accepted
31/31 cases passed (20 ms)
Your runtime beats 34.19 % of cpp submissions
Your memory usage beats 55.58 % of cpp submissions (13.9 MB)
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
    TreeNode *ret = nullptr;
    bool dfs(TreeNode *node, TreeNode *p, TreeNode *q)
    {
        if (node == nullptr)
            return false;
        bool left = dfs(node->left, p, q);
        bool right = dfs(node->right, p, q);

        if ((left && right) || (left || right) && (node->val == p->val || node->val == q->val))
        {
            ret = node;
        }

        return left || right || (node->val == p->val || node->val == q->val);
    }

public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        dfs(root, p, q);
        return ret;
    }
};
// @lc code=end
