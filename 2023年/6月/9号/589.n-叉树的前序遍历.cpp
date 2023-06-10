/*
 * @lc app=leetcode.cn id=589 lang=cpp
 *
 * [589] N 叉树的前序遍历
 */

#include <vector>
using namespace std;
// Definition for a Node.
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
38/38 cases passed (16 ms)
Your runtime beats 78.02 % of cpp submissions
Your memory usage beats 25.94 % of cpp submissions (11.3 MB)
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
    vector<int> ret;
    void dfs(Node *root)
    {
        if (root == nullptr)
        {
            return;
        }
        ret.push_back(root->val);
        for (int i = 0; i < root->children.size(); i++)
        {
            dfs(root->children[i]);
        }
    }

public:
    vector<int> preorder(Node *root)
    {
        dfs(root);
        return ret;
    }
};
// @lc code=end
