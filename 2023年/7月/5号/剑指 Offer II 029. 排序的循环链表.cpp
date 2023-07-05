/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/
#include <iostream>
// Definition for a Node.
class Node
{
public:
    int val;
    Node *next;

    Node() {}

    Node(int _val)
    {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node *_next)
    {
        val = _val;
        next = _next;
    }
};

class Solution
{
public:
    Node *insert(Node *head, int insertVal)
    {
        Node *node = new Node(insertVal);
        if (head == nullptr)
        {
            node->next = node;
            return node;
        }

        // 找到最大值节点(最后一个) maxNode：
        int max = head->val;
        Node *cur = head->next, *minNode = head, *maxNode = head;
        while (cur != head)
        {
            if (cur->val >= max)
            {
                max = cur->val;
                maxNode = cur;
            }
            cur = cur->next;
        }
        minNode = maxNode->next; // maxNode.next即为minNode

        // 如果插入值小于等于最小值，或者大于等于最大值，则直接插入到maxNode后面即可：
        if (insertVal <= minNode->val || insertVal >= maxNode->val)
        {
            node->next = minNode;
            maxNode->next = node;
            return head;
        }

        // 此时，新插入节点位于(minNode ~ maxNode)之间，cur从minNode开始遍历，找到第一个大于的节点即为插入点：
        cur = minNode;
        Node *pre = maxNode, *next = cur->next;
        while (cur->val < insertVal)
        {
            pre = cur;
            cur = next;
            next = cur->next;
        } // 将node插入到 pre 与 cur 之间
        pre->next = node;
        node->next = cur;
        return head;
    }
};