/*
 * @lc app=leetcode.cn id=117 lang=cpp
 *
 * [117] 填充每个节点的下一个右侧节点指针 II
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
 *
O(N)
Accepted
55/55 cases passed (16 ms)
Your runtime beats 42.85 % of cpp submissions
Your memory usage beats 5.06 % of cpp submissions (18.1 MB)
O(1)
55/55 cases passed (20 ms)
Your runtime beats 13.86 % of cpp submissions
Your memory usage beats 91.38 % of cpp submissions (16.9 MB)
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
// O(1)空间复杂度
class Solution
{
public:
    Node *connect(Node *root)
    {
        // 带头链表
        if (root == nullptr)
        {
            return nullptr;
        }
        Node *head = new Node(0); // 哨兵位
        Node *tail = head;
        Node *node = root;
        while (true)
        {
            while (node != nullptr)
            {
                if (node->left != nullptr)
                {
                    tail->next = node->left;
                    tail = tail->next;
                }
                if (node->right != nullptr)
                {
                    tail->next = node->right;
                    tail = tail->next;
                }
                node = node->next;
            }
            node = head->next;

            // 清空记录链表
            head->next = nullptr;
            tail = head;
            if (node == nullptr)
            {
                break;
            }
        }
        return root;
    }
};

// O(n空间复杂度)
//  class Solution
//  {
//      void display(Node *root, vector<vector<Node *>> &level)
//      {
//          queue<Node *> q;
//          q.push(root);
//          while (!q.empty())
//          {
//              int size = q.size();
//              vector<Node *> msg;
//              for (int i = 0; i < size; i++)
//              {
//                  Node *node = q.front();
//                  msg.push_back(node);
//                  q.pop();
//                  if (node->left != nullptr)
//                  {
//                      q.push(node->left);
//                  }
//                  if (node->right != nullptr)
//                  {
//                      q.push(node->right);
//                  }
//              }
//              level.push_back(msg);
//          }
//      }

// public:
//     Node *connect(Node *root)
//     {
//         if (root == nullptr)
//             return nullptr;
//         vector<vector<Node *>> level;
//         display(root, level);

//         for (int i = 0; i < level.size(); i++)
//         {
//             for (int j = 0; j < level[i].size() - 1; j++)
//             {
//                 level[i][j]->next = level[i][j + 1];
//             }
//             level[i].back()->next = nullptr;
//         }
//         return root;
//     }
// };
// @lc code=end
