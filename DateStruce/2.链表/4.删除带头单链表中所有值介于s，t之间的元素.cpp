// 04.设在一个带表头结点的单链表中，所有结点的元素值无序，试编写一个函数，删除表中 所有介于给定的两个值(作为函数参数给出) 之间的元素(若存在)。
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

// 删除[s,t]之间的元素
void DeleteListNodeByValue(ListNode *listNode, ElemType s, ElemType t)
{
    if (s > t)
    {
        return;
    }
    // 带头节点
    ListNode *prev = listNode;
    ListNode *cur = listNode->next;
    while (cur != nullptr)
    {
        if (cur->data >= s && cur->data <= t)
        {
            // 删除节点
            prev->next = cur->next;
            delete cur;
            cur = prev->next;
        }
        else
        {
            prev = cur;
            cur = cur->next;
        }
    }
}

int main(int argc, char const *argv[])
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    ListNode *listNode = CreateListNodeByArray(arr, n);
    PrintList(listNode);
    DeleteListNodeByValue(listNode, 1, 9);
    PrintList(listNode);
    return 0;
}
