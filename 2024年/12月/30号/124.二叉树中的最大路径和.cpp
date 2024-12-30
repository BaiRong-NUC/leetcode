/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
 */
#include<iostream>
#include <algorithm>
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
class Solution {
    int ret = INT_MIN;
public:
    int maxPathSum(TreeNode* root) {
       if(root==nullptr){
           return 0;
       }
       LastOrderDisplay(root);
       return ret;
    }
    /**
     * @brief 返回值为每个节点可以为最大路径贡献的值
     */
    int LastOrderDisplay(TreeNode* root){
        if(root==nullptr){
            return 0;
        }
        //节点左子树贡献的值
        int left = max(LastOrderDisplay(root->left), 0);
        //节点右子树贡献的值
        int right = max(LastOrderDisplay(root->right), 0);
        //更新答案
        ret = max(ret, left + right + root->val);
        // 返回节点的贡献值
        return max(left, right) + root->val;
    }
};
// @lc code=end