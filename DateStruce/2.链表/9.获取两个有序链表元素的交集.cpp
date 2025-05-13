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

ListNode *CreateCommonList(ListNode *pHead1, ListNode *pHead2)
{
    ListNode *curA = pHead1->next;
    ListNode *curB = pHead2->next;
    ListNode *commonHead = new ListNode;
    ListNode *commonCur = commonHead;
    while (curA != nullptr && curB != nullptr)
    {
        if (curA->data == curB->data)
        {
            ListNode *newNode = new ListNode;
            newNode->data = curA->data;
            newNode->next = nullptr;
            commonCur->next = newNode;
            commonCur = commonCur->next;
            curA = curA->next;
            curB = curB->next;
        }
        else
        {
            // 让最小的链表
            curA->data < curB->data ? curA = curA->next : curB = curB->next;
        }
    }
    return commonHead;
}

int main(int argc, char const *argv[])
{
    int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int arr2[] = {1, 2, 3, 4, 5, 7, 9, 11, 12};
    ListNode *listNode1 = CreateListNodeByArray(arr1, sizeof(arr1) / sizeof(arr1[0]));
    ListNode *listNode2 = CreateListNodeByArray(arr2, sizeof(arr2) / sizeof(arr2[0]));
    PrintList(listNode1);
    PrintList(listNode2);
    ListNode *commonList = CreateCommonList(listNode1, listNode2);
    PrintList(commonList);
    return 0;
}
