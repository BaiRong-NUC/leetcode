/*
 * @lc app=leetcode.cn id=508 lang=cpp
 *
 * [508] 出现次数最多的子树元素和
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
#include <iostream>
using namespace std;
/**
Accepted
58/58 cases passed (20 ms)
Your runtime beats 50.32 % of cpp submissions
Your memory usage beats 5.1 % of cpp submissions (27.2 MB)
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
    unordered_map<TreeNode *, int> _hash;

    unordered_map<int, int> count;

    int maxTimes = 0;

    int _init_count(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        int val = 0;
        if (_hash.count(root))
        {
            val = _hash[root];
        }
        else
        {
            val = root->val + _init_count(root->left) + _init_count(root->right);
            _hash[root] = val;
        }
        count[val] += 1;
        maxTimes = max(maxTimes, count[val]);
        return val;
    }

public:
    vector<int> findFrequentTreeSum(TreeNode *root)
    {
        _init_count(root);

        vector<int> ret;
        for (auto pos = count.begin(); pos != count.end(); pos++)
        {
            if (pos->second == maxTimes)
            {
                ret.push_back(pos->first);
            }
        }
        return ret;
    }
};
// @lc code=end
