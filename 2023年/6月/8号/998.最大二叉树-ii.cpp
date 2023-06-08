/*
 * @lc app=leetcode.cn id=998 lang=cpp
 *
 * [998] 最大二叉树 II
 */

/**
Accepted
75/75 cases passed (4 ms)
Your runtime beats 77.71 % of cpp submissions
Your memory usage beats 43.98 % of cpp submissions (13.1 MB)
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
    TreeNode *insertIntoMaxTree(TreeNode *root, int val)
    {
        TreeNode *prev = nullptr;
        TreeNode *node = root;
        while (node != nullptr)
        {
            if (node->val < val)
            {
                if (prev == nullptr)
                {
                    return new TreeNode(val, root, nullptr);
                }
                TreeNode *newNode = new TreeNode(val, node, nullptr);
                prev->right = newNode;
                return root;
            }
            else
            {
                prev = node;
                node = node->right;
            }
        }
        prev->right = new TreeNode(val);
        return root;
    }
};
// @lc code=end
