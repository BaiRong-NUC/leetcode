/**
 * 设A和B是两个单链表(带头结点)，其中元素递增有序。设计一个算法从A和B中的公共元素产生单链表C，要求不破坏A、B 的结点。
 */

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

ListNode *FindFirstCommonNode(ListNode *pHead1, ListNode *pHead2)
{
    if (pHead1 == nullptr || pHead2 == nullptr)
        return nullptr;
    ListNode *p1 = pHead1->next; // 跳过头节点
    ListNode *p2 = pHead2->next; // 跳过头节点
    while (p1 != p2)
    {
        p1 = p1->next == nullptr ? pHead2->next : p1->next;
        p2 = p2->next == nullptr ? pHead1->next : p2->next;
    }
    return p1;
}
ListNode *CreateCommonList(ListNode *pHead1, ListNode *pHead2)
{
    ListNode *commonNode = FindFirstCommonNode(pHead1, pHead2);
    // 构造头节点
    ListNode *newHead = new ListNode;
    newHead->next = commonNode;
    return newHead;
}

int main(int argc, char const *argv[])
{
    // 测试案例1：有公共节点
    int arr1[] = {1, 2, 3};
    int arr2[] = {4, 5};
    int arrCommon[] = {6, 7, 8};

    ListNode *headA = CreateListNodeByArray(arr1, 3);
    ListNode *headB = CreateListNodeByArray(arr2, 2);

    // 创建公共节点部分
    ListNode *common = CreateListNodeByArray(arrCommon, 3);

    // 将两个链表连接到公共节点
    ListNode *tailA = headA;
    while (tailA->next != nullptr)
        tailA = tailA->next;
    tailA->next = common->next;

    ListNode *tailB = headB;
    while (tailB->next != nullptr)
        tailB = tailB->next;
    tailB->next = common->next;

    cout << "List A: ";
    PrintList(headA);
    cout << "List B: ";
    PrintList(headB);

    ListNode *result = CreateCommonList(headA, headB);
    cout << "Common List: ";
    PrintList(result);
    return 0;
}
