/*
 * @lc app=leetcode.cn id=652 lang=cpp
 *
 * [652] 寻找重复的子树
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
#include <unordered_map>
#include <string>
#include <unordered_set>
using namespace std;

/**
Accepted
175/175 cases passed (28 ms)
Your runtime beats 57.29 % of cpp submissions
Your memory usage beats 85.6 % of cpp submissions (35.8 MB)
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
    vector<TreeNode *> findDuplicateSubtrees(TreeNode *root)
    {
        dfs(root);
        return {repeat.begin(), repeat.end()};
    }

    string dfs(TreeNode *node)
    {
        if (!node)
        {
            return "";
        }
        string serial = to_string(node->val) + "(" + dfs(node->left) + ")(" + dfs(node->right) + ")";
        if (auto it = seen.find(serial); it != seen.end())
        {
            repeat.insert(it->second);
        }
        else
        {
            seen[serial] = node;
        }
        return serial;
    }

private:
    unordered_map<string, TreeNode *> seen;
    unordered_set<TreeNode *> repeat;
};
// @lc code=end
