/*
 * @lc app=leetcode.cn id=501 lang=cpp
 *
 * [501] 二叉搜索树中的众数
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
#include <unordered_map>
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
private:
    unordered_map<int, int> _hash;
    void Inorder(TreeNode *node, vector<TreeNode *> &buff)
    {
        if (node == nullptr)
        {
            return;
        }
        Inorder(node->left, buff);
        _hash[node->val] += 1;
        buff.push_back(node);
        Inorder(node->right, buff);
    }

public:
    vector<int> findMode(TreeNode *root)
    {
        vector<TreeNode *> buff;
        Inorder(root, buff);
        // cout << _hash[buff[0]->val] << " " << _hash[buff[1]->val] << endl;
        int max = 0;
        vector<int> ret;
        for (int i = 0; i < buff.size(); i++)
        {
            if (max < _hash[buff[i]->val])
            {
                max = _hash[buff[i]->val];
            }
        }
        // cout << max << endl;
        for (int i = 0; i < buff.size(); i++)
        {
            if (_hash[buff[i]->val] == max && find(ret.begin(), ret.end(), buff[i]->val) == ret.end())
            {
                ret.push_back(buff[i]->val);
            }
        }
        return ret;
    }
};
// @lc code=end
