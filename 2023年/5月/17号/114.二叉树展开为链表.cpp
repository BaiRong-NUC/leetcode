/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
 */
#include <iostream>
#include <vector>
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
/**
Accepted
225/225 cases passed (8 ms)
Your runtime beats 54.13 % of cpp submissions
Your memory usage beats 5.53 % of cpp submissions (12.8 MB)
*/
class Solution
{
    void display(vector<TreeNode *> &preDisplay, TreeNode *root)
    {
        if (root == nullptr)
            return;
        preDisplay.push_back(root);
        display(preDisplay, root->left);
        display(preDisplay, root->right);
    }

public:
    void flatten(TreeNode *root)
    {
        if (root == nullptr)
            return;
        vector<TreeNode *> preDisplay;
        display(preDisplay, root);
        // 构造链表
        for (int i = 0; i < preDisplay.size() - 1; i++)
        {
            TreeNode *node = preDisplay[i];
            node->left = nullptr;
            node->right = preDisplay[i + 1];
        }
        preDisplay[preDisplay.size() - 1]->left = nullptr;
        preDisplay[preDisplay.size() - 1]->right = nullptr;
    }
};
// @lc code=end
