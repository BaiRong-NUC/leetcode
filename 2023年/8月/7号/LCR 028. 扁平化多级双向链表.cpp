
#include <stack>
using namespace std;
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
class Node
{
public:
    int val;
    Node *prev;
    Node *next;
    Node *child;
};

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
            if (cur->child != nullptr)
            {
                if (cur->next != nullptr)
                {
                    // 保存下一个节点位置，child链表扁平化
                    childs.push(cur->next);
                }
                Node *child = cur->child;
                cur->next = child;
                child->prev = cur;
                cur->child = nullptr; // 切记扁平化后，child指针置空，否则过不了
            }
            prev = cur;
            cur = cur->next;
        }
        return head;
    }
};