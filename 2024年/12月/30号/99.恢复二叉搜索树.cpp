/*
 * @lc app=leetcode.cn id=99 lang=cpp
 *
 * [99] 恢复二叉搜索树
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
class Solution
{
public:
    void recoverTree(TreeNode *root)
    {
        stack<TreeNode *> st;
        // left,right保存两个错误的节点
        TreeNode *left = nullptr;
        TreeNode *right = nullptr;
        // 保存中序遍历前一个结点
        TreeNode *prev = nullptr;
        while (root != nullptr || !st.empty())
        {
            while (root != nullptr)
            {
                st.push(root);
                root = root->left;
            }
            root = st.top();
            st.pop();
            // 一共两个错误节点，分别保存到left和right中
            if (prev != nullptr && prev->val > root->val)
            {
                if (left == nullptr)
                {
                    left = prev;
                }
                right = root;
            }
            prev = root;
            root = root->right;
        }
        // 交换两个错误节点的值
        swap(left->val, right->val);
    }
};
// @lc code=end
