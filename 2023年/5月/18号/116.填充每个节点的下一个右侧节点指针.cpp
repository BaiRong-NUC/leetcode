/*
 * @lc app=leetcode.cn id=116 lang=cpp
 *
 * [116] 填充每个节点的下一个右侧节点指针
 */
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

/**
Accepted
59/59 cases passed (20 ms)
Your runtime beats 62.64 % of cpp submissions
Your memory usage beats 5.02 % of cpp submissions (17.7 MB)
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution
{
    void display(Node *root, vector<vector<Node *>> &level)
    {
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            int size = q.size();
            vector<Node *> msg;
            for (int i = 0; i < size; i++)
            {
                Node *node = q.front();
                msg.push_back(node);
                q.pop();
                if (node->left != nullptr)
                {
                    q.push(node->left);
                }
                if (node->right != nullptr)
                {
                    q.push(node->right);
                }
            }
            level.push_back(msg);
        }
    }

public:
    Node *connect(Node *root)
    {
        if (root == nullptr)
            return nullptr;
        vector<vector<Node *>> level;
        display(root, level);

        for (int i = 0; i < level.size(); i++)
        {
            for (int j = 0; j < level[i].size() - 1; j++)
            {
                level[i][j]->next = level[i][j + 1];
            }
            level[i].back()->next = nullptr;
        }
        return root;
    }
};
// @lc code=end
