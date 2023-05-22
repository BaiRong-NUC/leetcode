/*
 * @lc app=leetcode.cn id=230 lang=cpp
 *
 * [230] 二叉搜索树中第K小的元素
 */
#include <unordered_map>
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
93/93 cases passed (20 ms)
Your runtime beats 41.25 % of cpp submissions
Your memory usage beats 5.02 % of cpp submissions (27.5 MB)
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
    unordered_map<TreeNode *, int> _hash;
    int CountTree(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        _hash[root] = 1 + CountTree(root->left) + CountTree(root->right);
        return _hash[root];
    }

    int kSmall(TreeNode *root, int k)
    {
        if (root == nullptr)
            return 0;
        int leftCount = _hash[root->left];
        if (leftCount == k - 1)
        {
            return root->val;
        }
        else if (leftCount < k - 1)
        {
            return kSmall(root->right, k - leftCount - 1);
        }
        else
        {
            return kSmall(root->left, k);
        }
    }

public:
    int kthSmallest(TreeNode *root, int k)
    {
        CountTree(root);
        return kSmall(root, k);
    }
};
// @lc code=end
