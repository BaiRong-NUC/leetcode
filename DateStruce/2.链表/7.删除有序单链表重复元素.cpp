#include <iostream>
using namespace std;
#define ElemType int
typedef struct ListNode
{
    ElemType data;
    struct ListNode *next;
} ListNode;

void PrintList(ListNode *listNode)
{
    ListNode *cur = listNode->next;
    if (cur == nullptr)
    {
        cout << "链表为空" << endl;
    }
    while (cur != nullptr)
    {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << endl;
}

ListNode *CreateListNodeByArray(ElemType arr[], int n)
{
    ListNode *listNode = new ListNode;
    ListNode *cur = listNode;
    for (int i = 0; i < n; i++)
    {
        ListNode *newNode = new ListNode;
        newNode->data = arr[i];
        newNode->next = nullptr;
        cur->next = newNode;
        cur = cur->next;
    }
    return listNode;
}

void delSameListNode(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return;
    ListNode *prev = head->next;
    ListNode *cur = prev->next;
    while (cur != nullptr)
    {
        ListNode *next = cur->next;
        if (cur->data == prev->data)
        {
            // 删除cur节点
            prev->next = next;
            delete cur;
            cur = next;
        }
        else
        {
            prev = cur;
            cur = next;
        }
    }
}

int main(int argc, char const *argv[])
{
    int array[] = {1, 1};
    ListNode *head = CreateListNodeByArray(array, sizeof(array) / sizeof(int));
    PrintList(head);
    delSameListNode(head);
    PrintList(head);
    return 0;
}
