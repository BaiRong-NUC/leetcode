/*
 * @lc app=leetcode.cn id=919 lang=cpp
 *
 * [919] 完全二叉树插入器
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

#include <queue>
#include <stack>
using namespace std;

/**
Accepted
85/85 cases passed (20 ms)
Your runtime beats 64.63 % of cpp submissions
Your memory usage beats 35.37 % of cpp submissions (22 MB)
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
class CBTInserter
{
    TreeNode *root = nullptr;
    queue<TreeNode *> next;

public:
    CBTInserter(TreeNode *root)
    {
        this->root = root;
        queue<TreeNode *> q;
        // 层序遍历树
        q.push(root);
        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode *node = q.front();
                q.pop();
                if (node->left == nullptr || node->right == nullptr)
                {
                    next.push(node);
                }
                if (node->left != nullptr)
                    q.push(node->left);
                if (node->right != nullptr)
                    q.push(node->right);
            }
        }
    }

    int insert(int val)
    {
        TreeNode *node = next.front();
        TreeNode *newnode = new TreeNode(val);
        node->left == nullptr ? (node->left = newnode) : (next.pop(), node->right = newnode);
        next.push(newnode);
        return node->val;
    }

    TreeNode *get_root()
    {
        return root;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */
// @lc code=end
