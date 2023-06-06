/*
 * @lc app=leetcode.cn id=1008 lang=cpp
 *
 * [1008] 前序遍历构造二叉搜索树
 */
#include <vector>
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
111/111 cases passed (0 ms)
Your runtime beats 100 % of cpp submissions
Your memory usage beats 92.74 % of cpp submissions (12.2 MB)
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
    void insert(TreeNode *root, int val)
    {
        if (root->val > val)
        {
            if (root->left == nullptr)
                root->left = new TreeNode(val);
            else
                insert(root->left, val);
        }
        else
        {
            if (root->right == nullptr)
                root->right = new TreeNode(val);
            else
                insert(root->right, val);
        }
    }

public:
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        TreeNode *root = new TreeNode(preorder[0]);
        for (int i = 1; i < preorder.size(); i++)
        {
            insert(root, preorder[i]);
        }
        return root;
    }
};
// @lc code=end
