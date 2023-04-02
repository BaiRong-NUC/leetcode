/*
 * @lc app=leetcode.cn id=637 lang=cpp
 *
 * [637] 二叉树的层平均值
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
#include <queue>
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
    double average(queue<TreeNode *> buff)
    {
        double sum = 0.0;
        int size = buff.size();
        while (!buff.empty())
        {
            sum += buff.front()->val;
            buff.pop();
        }
        return sum / size;
    }

public:
    vector<double> averageOfLevels(TreeNode *root)
    {
        vector<double> ret;
        queue<TreeNode *> pos;
        queue<TreeNode *> next;
        pos.push(root);
        while (!pos.empty() || !next.empty())
        {
            ret.push_back(average(pos));
            while (!pos.empty()) // 本层节点处理
            {
                TreeNode *node = pos.front();
                pos.pop();
                if (node->left != nullptr)
                {
                    next.push(node->left);
                }
                if (node->right != nullptr)
                {
                    next.push(node->right);
                }
            }
            pos.swap(next);
        }
        return ret;
    }
};
// @lc code=end
