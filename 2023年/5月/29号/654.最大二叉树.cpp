/*
 * @lc app=leetcode.cn id=654 lang=cpp
 *
 * [654] 最大二叉树
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
#include <vector>
#include <algorithm>
using namespace std;

/**
Accepted
107/107 cases passed (92 ms)
Your runtime beats 51.44 % of cpp submissions
Your memory usage beats 60.28 % of cpp submissions (41.2 MB)
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
    int find(vector<int> &nums, int begin, int end)
    {
        int max = begin;
        for (int i = begin; i <= end; i++)
        {
            if (nums[i] > nums[max])
            {
                max = i;
            }
        }
        return max;
    }

    TreeNode *creatTree(vector<int> &nums, int begin, int end)
    {
        if (begin > end)
        {
            return nullptr;
        }
        int pos = find(nums, begin, end);
        TreeNode *root = new TreeNode(nums[pos]);
        root->left = creatTree(nums, begin, pos - 1);
        root->right = creatTree(nums, pos + 1, end);
        return root;
    }

public:
    TreeNode *constructMaximumBinaryTree(vector<int> &nums)
    {
        return creatTree(nums, 0, nums.size() - 1);
    }
};
// @lc code=end
