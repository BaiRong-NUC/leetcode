/*
 * @lc app=leetcode.cn id=671 lang=cpp
 *
 * [671] 二叉树中第二小的节点
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
#include <string>
#include <algorithm>
#include <iostream>
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
    int min = 0;
    int second_min = -1;

    void InorderDisPlay(TreeNode *node)
    {
        if (node == nullptr)
        {
            return;
        }
        int val = node->val;

        if (val != min)
        {
            if (second_min == -1)
            {
                second_min = node->val;
            }
            else
            {
                second_min = std::min(second_min, node->val);
            }
        }
        InorderDisPlay(node->left);
        InorderDisPlay(node->right);
    }

public:
    int findSecondMinimumValue(TreeNode *root)
    {
        if (root == nullptr)
        {
            return -1;
        }
        // 小根堆,堆顶是最小值
        this->min = root->val;
        InorderDisPlay(root);
        return second_min;
    }
};
// @lc code=end
