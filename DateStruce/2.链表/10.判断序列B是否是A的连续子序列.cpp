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

// 暴力匹配
bool IsSubsequence(ListNode *listNodeA, ListNode *listNodeB)
{
    ListNode *curA = listNodeA->next;
    ListNode *curB = listNodeB->next;
    while (curA != nullptr)
    {
        ListNode *next = curA->next;
        while (curB != nullptr && curA != nullptr && curA->data == curB->data)
        {
            curA = curA->next;
            curB = curB->next;
        }
        if (curB == nullptr)
        {
            return true;
        }
        else
        {
            curA = next;
            curB = listNodeB->next;
        }
    }
    return false;
}

int main(int argc, char const *argv[])
{
    ListNode *listNodeA = CreateListNodeByArray(new ElemType[5]{1, 2, 3, 4, 5}, 5);
    ListNode *listNodeB = CreateListNodeByArray(new ElemType[5]{3, 5, 4}, 3);
    PrintList(listNodeA);
    PrintList(listNodeB);
    cout << IsSubsequence(listNodeA, listNodeB) << endl;
    return 0;
}
