/*
 * @lc app=leetcode.cn id=971 lang=cpp
 *
 * [971] 翻转二叉树以匹配先序遍历
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


/**
Accepted
104/104 cases passed (4 ms)
Your runtime beats 70.75 % of cpp submissions
Your memory usage beats 78.23 % of cpp submissions (13.4 MB)
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
    vector<int> voyage;
    int index = 0;
    vector<int> ret;

    bool dfs(TreeNode *root)
    {
        if (root == nullptr)
        {
            return true;
        }
        if (root->val != voyage[index++])
        {
            return false;
        }
        if (root->left != nullptr && root->left->val != voyage[index])
        {
            // 翻转二叉树
            ret.push_back(root->val);
            return dfs(root->right) && dfs(root->left);
        }
        else
        {
            return dfs(root->left) && dfs(root->right);
        }
    }

public:
    vector<int> flipMatchVoyage(TreeNode *root, vector<int> &voyage)
    {
        this->voyage = voyage;
        if (dfs(root))
        {
            return ret;
        }
        return {-1};
    }
};
// @lc code=end
