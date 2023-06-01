/*
 * @lc app=leetcode.cn id=894 lang=cpp
 *
 * [894] 所有可能的真二叉树
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
    unordered_map<int, vector<TreeNode *>> _hash;

public:
    vector<TreeNode *> allPossibleFBT(int n)
    {
        if (!_hash.count(n))
        {
            vector<TreeNode *> ret;
            if (n == 1)
            {
                ret.push_back(new TreeNode(0));
            }
            else if (n % 2 == 1)
            {
                for (int x = 0; x < n; x++)
                {
                    int y = n - x - 1; // 去掉一个根节点
                    for (TreeNode *left : allPossibleFBT(x))
                    {
                        for (TreeNode *right : allPossibleFBT(y))
                        {
                            TreeNode *node = new TreeNode(0);
                            node->left = left;
                            node->right = right;
                            ret.push_back(node);
                        }
                    }
                }
            }
            // 偶数不可能构造出真二叉树
            _hash[n] = ret;
        }
        return _hash[n];
    }
};
// @lc code=end
