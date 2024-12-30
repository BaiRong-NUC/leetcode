/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
 */
#include <D:\CppCode\leetcode\global\global.h>
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
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr)
        {
            return 0;
        }
        // 层序遍历获取二叉树最小深度
        queue<TreeNode *> q;
        int depth = 1;
        q.push(root);
        while (!q.empty())
        {
            int size = q.size(); // 记录当前层的节点数
            for (int i = 0; i < size; i++)
            {
                TreeNode *node = q.front();
                q.pop();
                if (node->left == nullptr && node->right == nullptr){
                    return depth;
                }
                // 临近节点入队列
                if (node->left != nullptr)
                {
                    q.push(node->left);
                }
                if (node->right != nullptr)
                {
                    q.push(node->right);
                }
            }
            depth++;
        }
        return depth;
    }
};
// @lc code=end

