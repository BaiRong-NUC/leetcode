/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
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
115/115 cases passed (12 ms)
Your runtime beats 46.98 % of cpp submissions
Your memory usage beats 79.13 % of cpp submissions (19.3 MB)
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
    vector<int> path;
    void dfs(vector<vector<int>> &ret, TreeNode *root, int target, int val)
    {
        if (root == nullptr)
            return;
        if (root->left == nullptr && root->right == nullptr)
        {
            // 叶子节点
            val += root->val;
            if (target == val)
            {
                path.push_back(root->val);
                ret.push_back(path);
                path.pop_back();
            }
            return;
        }
        path.push_back(root->val);
        val += root->val;
        dfs(ret, root->left, target, val);
        dfs(ret, root->right, target, val);
        path.pop_back();
    }

public:
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        vector<vector<int>> ret;
        dfs(ret, root, targetSum, 0);
        return ret;
    }
};
// @lc code=end
