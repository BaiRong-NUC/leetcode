/*
 * @lc app=leetcode.cn id=617 lang=cpp
 *
 * [617] 合并二叉树
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
    void InorderMerge(TreeNode *&leftTree, TreeNode *&rightTree)
    {
        if (leftTree == nullptr && rightTree == nullptr)
        {
            return;
        }
        if (leftTree != nullptr && rightTree == nullptr)
        {
            return;
        }
        if (leftTree == nullptr && rightTree != nullptr)
        {
            leftTree = rightTree;
            return;
        }
        InorderMerge(leftTree->left, rightTree->left);
        leftTree->val += rightTree->val;
        InorderMerge(leftTree->right, rightTree->right);
    }

public:
    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
    {
        InorderMerge(root1, root2);
        return root1;
    }
};
// @lc code=end
