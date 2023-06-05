/*
 * @lc app=leetcode.cn id=559 lang=cpp
 *
 * [559] N 叉树的最大深度
 */

#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;
class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};

/**
Accepted
38/38 cases passed (12 ms)
Your runtime beats 93.8 % of cpp submissions
Your memory usage beats 93.44 % of cpp submissions (10.4 MB)
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution
{
    int dfs(Node *root)
    {
        if (root == nullptr)
            return 0;
        int deep = 0;
        for (int i = 0; i < root->children.size(); i++)
        {
            deep = max(deep, dfs(root->children[i]));
        }
        return deep + 1;
    }

public:
    int maxDepth(Node *root)
    {
        return dfs(root);
    }
};
// @lc code=end
