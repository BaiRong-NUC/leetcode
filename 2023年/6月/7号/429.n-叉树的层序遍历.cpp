/*
 * @lc app=leetcode.cn id=429 lang=cpp
 *
 * [429] N 叉树的层序遍历
 */

#include <vector>
#include <queue>
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
38/38 cases passed (20 ms)
Your runtime beats 41.31 % of cpp submissions
Your memory usage beats 59.93 % of cpp submissions (11.6 MB)
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
public:
    vector<vector<int>> levelOrder(Node *root)
    {
        vector<vector<int>> ret;
        if (root == nullptr)
            return ret;
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            int size = q.size();
            vector<int> level;
            for (int i = 0; i < size; i++)
            {
                Node *node = q.front();
                q.pop();
                level.push_back(node->val);
                for (auto &child : node->children)
                {
                    q.push(child);
                }
            }
            ret.push_back(level);
        }
        return ret;
    }
};
// @lc code=end
