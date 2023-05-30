/*
 * @lc app=leetcode.cn id=662 lang=cpp
 *
 * [662] 二叉树最大宽度
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
#include <string>
#include <unordered_map>
#include <vector>
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

/**
Accepted
114/114 cases passed (4 ms)
Your runtime beats 98.43 % of cpp submissions
Your memory usage beats 46.57 % of cpp submissions (17.1 MB)
 */

class Solution
{
public:
    int widthOfBinaryTree(TreeNode *root)
    {
        unsigned long long ret = 0;
        vector<pair<TreeNode *, unsigned long long>> array;
        array.emplace_back(root, 1L);
        while (!array.empty())
        {
            vector<pair<TreeNode *, unsigned long long>> next;
            for (auto &[node, index] : array)
            {
                if (node->left != nullptr)
                    next.emplace_back(node->left, index * 2);
                if (node->right != nullptr)
                    next.emplace_back(node->right, index * 2 + 1);
            }
            ret = max(ret, array.back().second - array[0].second + 1);
            array.swap(next);
        }
        return ret;
    }
};
// @lc code=end
