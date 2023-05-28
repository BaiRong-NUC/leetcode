/*
 * @lc app=leetcode.cn id=623 lang=cpp
 *
 * [623] 在二叉树中增加一行
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
#include <queue>
using namespace std;

/**
Accepted
109/109 cases passed (16 ms)
Your runtime beats 82.95 % of cpp submissions
Your memory usage beats 36.13 % of cpp submissions (24.4 MB)
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
    TreeNode *addOneRow(TreeNode *root, int val, int depth)
    {
        if (depth == 1)
        {
            TreeNode *node = new TreeNode(val);
            node->left = root;
            return node;
        }
        queue<TreeNode *> q;
        q.push(root);
        int level = 1;
        depth -= 1;
        while (!q.empty())
        {
            int size = q.size();
            if (level == depth)
            {
                // 队列内的节点为需要添加的节点
                for (int i = 0; i < size; i++)
                {
                    TreeNode *node = q.front();
                    q.pop();
                    TreeNode *left = new TreeNode(val);
                    left->left = node->left;
                    TreeNode *right = new TreeNode(val);
                    right->right = node->right;
                    node->left = left;
                    node->right = right;
                }
                break;
            }
            else
            {
                for (int i = 0; i < size; i++)
                {
                    TreeNode *node = q.front();
                    q.pop();
                    if (node->left != nullptr)
                        q.push(node->left);
                    if (node->right != nullptr)
                        q.push(node->right);
                }
                level += 1;
            }
        }
        return root;
    }
};
// @lc code=end
