/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
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
#include <string>
using namespace std;
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
private:
    void dfs(TreeNode *root, vector<string> &vet, vector<string> &path)
    {
        if (root == nullptr)
        {
            return;
        }
        if (root->left == nullptr && root->right == nullptr)
        {
            // 叶子节点
            path.push_back(to_string(root->val));
            string path_line = "";
            for (int i = 0; i < path.size() - 1; i++)
            {
                path_line += path[i];
                path_line += "->";
            }
            path_line += path[path.size() - 1];
            vet.push_back(path_line);
            path.pop_back();
            return;
        }
        path.push_back(to_string(root->val));
        dfs(root->left, vet, path);
        dfs(root->right, vet, path);
        path.pop_back();
    }

public:
    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> ret;
        vector<string> path;
        dfs(root, ret, path);
        return ret;
    }
};
// @lc code=end
