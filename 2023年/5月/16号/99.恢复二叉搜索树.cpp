/*
 * @lc app=leetcode.cn id=99 lang=cpp
 *
 * [99] 恢复二叉搜索树
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
#include <vector>
using namespace std;

/**
Accepted
1919/1919 cases passed (20 ms)
Your runtime beats 91.9 % of cpp submissions
Your memory usage beats 35.31 % of cpp submissions (56.8 MB)
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
    void inorderDisplay(TreeNode *root, vector<int> &display)
    {
        if (root == nullptr)
            return;
        inorderDisplay(root->left, display);
        display.push_back(root->val);
        inorderDisplay(root->right, display);
    }

    pair<int, int> findError(vector<int> &display)
    {
        int left = -1;
        int right = -1;
        for (int i = 0; i < display.size() - 1; i++)
        {
            if (display[i] > display[i + 1])
            {
                right = i + 1;
                if (left == -1)
                {
                    left = i;
                }
                else
                {
                    break;
                }
            }
        }
        return make_pair(display[left], display[right]);
    }

    void recover(TreeNode *root, int left, int right)
    {
        if (root == nullptr)
            return;
        if (root->val == left || root->val == right)
        {
            root->val == left ? root->val = right : root->val = left;
        }
        recover(root->left, left, right);
        recover(root->right, left, right);
    }

public:
    void recoverTree(TreeNode *root)
    {
        // 正常递归遍历树，不适用morris遍历
        vector<int> display;
        inorderDisplay(root, display);
        // 找两个顺序错误的值
        pair<int, int> error = findError(display);
        // 恢复二叉树
        recover(root, error.first, error.second);
    }
};
// @lc code=end
