/*
 * @lc app=leetcode.cn id=968 lang=cpp
 *
 * [968] 监控二叉树
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
171/171 cases passed (8 ms)
Your runtime beats 77.59 % of cpp submissions
Your memory usage beats 5.02 % of cpp submissions (26.5 MB)
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
    // 自底向下遍历
    vector<int> minCamera(TreeNode *root)
    {
        // 状态0：当前节点安装相机的时候，需要的最少相机数
        // 状态1： 当前节点不安装相机，但是能被覆盖到的时候，需要的最少相机数
        // 状态2：当前节点不安装相机，也不能被覆盖到的时候，需要的最少相机数
        vector<int> dp(3, 0);
        if (root == nullptr)
        {
            dp[0] = INT_MAX / 2;
            dp[2] = INT_MAX / 2;
            return dp;
        }
        vector<int> left = minCamera(root->left);
        vector<int> right = minCamera(root->right);
        // 安装相机，其左孩子节点和右孩子节点都可以安装或者不装，但是总相机数+1
        dp[0] = min(left[0], min(left[1], left[2])) + min(right[0], min(right[1], right[2])) + 1;
        // 不安装相机，但是能被覆盖到，说明其孩子节点至少有一个安装了相机
        dp[1] = min(left[0] + min(right[0], right[1]), right[0] + min(left[0], left[1]));
        // 不安装相机，也不能被覆盖到，说明其孩子节点都没有安装相机，因为自己没有安装相机，其孩子节点也必须是已被覆盖到的
        dp[2] = left[1] + right[1];
        return dp;
    }

public:
    int minCameraCover(TreeNode *root)
    {
        vector<int> ret = minCamera(root);
        return min(ret[0], ret[1]);
    }
};
// @lc code=end
