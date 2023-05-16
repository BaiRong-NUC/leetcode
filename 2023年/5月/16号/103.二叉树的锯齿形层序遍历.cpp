/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层序遍历
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
33/33 cases passed (4 ms)
Your runtime beats 61.33 % of cpp submissions
Your memory usage beats 60.72 % of cpp submissions (11.8 MB)
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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        // 之字形层序遍历
        vector<vector<int>> ret;
        if (root == nullptr)
        {
            return ret;
        }
        queue<TreeNode *> q;
        q.push(root);
        int level = 1;
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
            if (level % 2 == 0)
                std::reverse(levelMsg.begin(), levelMsg.end());
            level += 1;
            ret.push_back(levelMsg);
        }
        return ret;
    }
};
// @lc code=end
