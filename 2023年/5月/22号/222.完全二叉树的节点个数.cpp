/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 完全二叉树的节点个数
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
#include <unordered_map>
using namespace std;

/**
Accepted
18/18 cases passed (48 ms)
Your runtime beats 6.66 % of cpp submissions
Your memory usage beats 5.06 % of cpp submissions (40.8 MB)
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

public:
    int countNodes(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        int ret = 0;
        if (_hash.count(root))
        {
            ret += _hash[root];
        }
        else
        {
            ret += countNodes(root->left) + countNodes(root->right);
            _hash[root] = ret;
        }
        return 1 + ret;
    }
};
// @lc code=end
