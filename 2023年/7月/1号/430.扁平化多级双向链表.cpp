/*
 * @lc app=leetcode.cn id=430 lang=cpp
 *
 * [430] 扁平化多级双向链表
 */
#include <stack>
#include <iostream>
using namespace std;
class Node
{
public:
    int val;
    Node *prev;
    Node *next;
    Node *child;
};

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/
class Solution
{
public:
    Node *flatten(Node *head)
    {
        stack<Node *> childs;
        Node *cur = head;
        Node *prev = nullptr;
        while (cur != nullptr || !childs.empty())
        {
            if (cur == nullptr && !childs.empty())
            {
                cur = childs.top();
                childs.pop();
                prev->next = cur;
                cur->prev = prev;
            }
            cout << cur->val << " ";
            if (cur->child != nullptr)
            {
                if (cur->next != nullptr)
                {
                    childs.push(cur->next);
                }
                Node *child = cur->child;
                cur->next = child;
                child->prev = cur;
                cur->child = nullptr;
            }
            prev = cur;
            cur = cur->next;
        }
        return head;
    }
};
// @lc code=end
