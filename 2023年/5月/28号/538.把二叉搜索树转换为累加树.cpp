/*
 * @lc app=leetcode.cn id=538 lang=cpp
 *
 * [538] 把二叉搜索树转换为累加树
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
#include <unordered_map>
#include <vector>
using namespace std;

/**
Accepted
215/215 cases passed (272 ms)
Your runtime beats 5.96 % of cpp submissions
Your memory usage beats 5.03 % of cpp submissions (34.9 MB)
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
    unordered_map<int, TreeNode *> _hash;
    vector<int> val;
    void inorder(TreeNode *root)
    {
        if (root == nullptr)
            return;
        inorder(root->left);
        _hash[root->val] = root;
        val.push_back(root->val);
        inorder(root->right);
    }

public:
    TreeNode *convertBST(TreeNode *root)
    {
        inorder(root);
        for (int i = 0; i < val.size(); i++)
        {
            TreeNode *node = _hash[val[i]];
            int sum = 0;
            for (int j = i; j < val.size(); j++)
            {
                sum += val[j];
            }
            node->val = sum;
        }
        return root;
    }
};
// @lc code=end
