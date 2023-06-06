/*
 * @lc app=leetcode.cn id=988 lang=cpp
 *
 * [988] 从叶结点开始的最小字符串
 */

#include <iostream>
#include <string>
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
69/69 cases passed (4 ms)
Your runtime beats 98.26 % of cpp submissions
Your memory usage beats 77.08 % of cpp submissions (19.1 MB)
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
    string min_str = "";

    void dfs(TreeNode *root, string str)
    {
        if (root == nullptr)
            return;
        if (root->left == nullptr && root->right == nullptr)
        {
            str += 'a' + root->val;
            string path(str.begin(), str.end());
            std::reverse(path.begin(), path.end());
            if (min_str == "")
            {
                min_str = path;
            }
            else if (min_str > path)
            {
                min_str = path;
            }
            return;
        }
        str += 'a' + root->val;
        dfs(root->left, str);
        dfs(root->right, str);
    }

public:
    string smallestFromLeaf(TreeNode *root)
    {
        string str = "";
        dfs(root, str);
        return min_str;
    }
};
// @lc code=end
