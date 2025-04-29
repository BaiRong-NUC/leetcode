// 3.试编写算法将带头结点的单链表就地逆置，所谓“就地”是指辅助空间复杂度为O(1)
#include <iostream>
using namespace std;
// 单链表
typedef int ElemType;
typedef struct ListNode
{
    ElemType data;
    struct ListNode *next;
} ListNode;

ListNode *CreatListNodeByArray(int a[], int n)
{
    ListNode *head = (ListNode *)malloc(sizeof(ListNode));
    ListNode *tail = head;
    head->next = nullptr;
    for (int i = 0; i < n; i++)
    {
        ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));
        newNode->data = a[i];
        newNode->next = nullptr;
        tail->next = newNode;
        tail = newNode;
    }
    return head;
}

// 逆置单链表
void ReverseListNode(ListNode *head)
{
    // 第一步摘头
    ListNode *cur = head->next;
    head->next = nullptr;
    // 每个元素从头插入
    while (cur != nullptr)
    {
        ListNode *next = cur->next;
        // cur节点头插到头节点上
        cur->next = head->next;
        head->next = cur;
        cur = next;
    }
}

void PrintListNode(ListNode *head)
{
    if (head->next == nullptr)
    {
        cout << "链表为空" << endl;
        return;
    }
    ListNode *p = head->next;
    while (p != nullptr)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    int a[] = {};
    int n = sizeof(a) / sizeof(a[0]);
    ListNode *head = CreatListNodeByArray(a, n);
    PrintListNode(head);
    ReverseListNode(head);
    PrintListNode(head);
    return 0;
}