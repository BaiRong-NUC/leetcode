/*
 * @lc app=leetcode.cn id=563 lang=cpp
 *
 * [563] 二叉树的坡度
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
#include <algorithm>

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
    // 返回一棵树的所有节点和
    int coutNum(TreeNode *node)
    {
        if (node == nullptr)
        {
            return 0;
        }
        int left = coutNum(node->left);
        int right = coutNum(node->right);
        return left + right + node->val;
    }

public:
    // 计算一个节点的坡度
    int coutSlop(TreeNode *node)
    {
        int left = coutNum(node->left);
        int right = coutNum(node->right);
        return std::abs(left - right);
    }
    void InorderDisplay(TreeNode *node, int &ret)
    {
        if (node == nullptr)
        {
            ret += 0;
            return;
        }
        InorderDisplay(node->left, ret);
        // cout << node->val << ":" << coutSlop(node) << endl;
        ret += coutSlop(node);
        InorderDisplay(node->right, ret);
    }
    int findTilt(TreeNode *root)
    {
        int ret = 0;
        InorderDisplay(root, ret);
        return ret;
    }
};
// @lc code=end
