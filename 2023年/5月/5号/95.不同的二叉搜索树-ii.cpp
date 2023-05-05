/*
 * @lc app=leetcode.cn id=95 lang=cpp
 *
 * [95] 不同的二叉搜索树 II
 */

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
Accepted
8/8 cases passed (16 ms)
Your runtime beats 77.29 % of cpp submissions
Your memory usage beats 32.62 % of cpp submissions (15.8 MB)
 */

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
    vector<TreeNode *> generateTrees(int start, int end)
    {
        if (start > end)
        {
            return {nullptr};
        }
        vector<TreeNode *> root;
        for (int i = start; i <= end; i++)
        {
            vector<TreeNode *> left = generateTrees(start, i - 1);
            vector<TreeNode *> right = generateTrees(i + 1, end);
            for (TreeNode *left : left)
            {
                for (TreeNode *right : right)
                {
                    TreeNode *node = new TreeNode(i);
                    node->left = left;
                    node->right = right;
                    root.push_back(node);
                }
            }
        }
        return root;
    }

public:
    vector<TreeNode *> generateTrees(int n)
    {
        if (n == 0)
        {
            return {};
        }
        return generateTrees(1, n);
    }
};
// @lc code=end
