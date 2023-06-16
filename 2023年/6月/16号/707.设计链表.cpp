/*
 * @lc app=leetcode.cn id=707 lang=cpp
 *
 * [707] 设计链表
 */
#include <iostream>
#include <unordered_map>
using namespace std;

struct ListNode
{
    ListNode *next;
    int val;
    ListNode(int _val) : next(nullptr), val(_val) {}
};
/**
Accepted
65/65 cases passed (44 ms)
Your runtime beats 35.18 % of cpp submissions
Your memory usage beats 90.53 % of cpp submissions (19.1 MB)
 */
// @lc code=start
class MyLinkedList
{
public:
    MyLinkedList()
    {
        this->size = 0;
        this->head = new ListNode(0);
    }

    int get(int index)
    {
        if (index < 0 || index >= size)
        {
            return -1;
        }
        ListNode *cur = head;
        for (int i = 0; i <= index; i++)
        {
            cur = cur->next;
        }
        return cur->val;
    }

    void addAtHead(int val)
    {
        addAtIndex(0, val);
    }

    void addAtTail(int val)
    {
        addAtIndex(size, val);
    }

    void addAtIndex(int index, int val)
    {
        if (index > size)
        {
            return;
        }
        index = max(0, index);
        size++;
        ListNode *pred = head;
        for (int i = 0; i < index; i++)
        {
            pred = pred->next;
        }
        ListNode *toAdd = new ListNode(val);
        toAdd->next = pred->next;
        pred->next = toAdd;
    }

    void deleteAtIndex(int index)
    {
        if (index < 0 || index >= size)
        {
            return;
        }
        size--;
        ListNode *pred = head;
        for (int i = 0; i < index; i++)
        {
            pred = pred->next;
        }
        ListNode *p = pred->next;
        pred->next = pred->next->next;
        delete p;
    }

private:
    int size;
    ListNode *head;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
// @lc code=end
