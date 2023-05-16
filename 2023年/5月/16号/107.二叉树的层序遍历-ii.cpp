/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层序遍历 II
 */

#include <vector>
#include <queue>
#include <algorithm>
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
34/34 cases passed (4 ms)
Your runtime beats 72.43 % of cpp submissions
Your memory usage beats 88.92 % of cpp submissions (12.1 MB)
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
public:
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        vector<vector<int>> ret;
        if (root == nullptr)
        {
            return ret;
        }
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int size = q.size();
            vector<int> levelMsg;
            for (int i = 0; i < size; i++)
            {
                TreeNode *cur = q.front();
                q.pop();
                levelMsg.push_back(cur->val);
                if (cur->left != nullptr)
                    q.push(cur->left);
                if (cur->right != nullptr)
                    q.push(cur->right);
            }
            ret.push_back(levelMsg);
        }
        std::reverse(ret.begin(), ret.end());
        return ret;
    }
};
// @lc code=end
