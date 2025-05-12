// 5. 找两个单链表的公共节点

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

// 计算链表长度
int GetListLength(ListNode *head)
{
    int len = 0;
    ListNode *cur = head->next; // 跳过头节点
    while (cur != nullptr)
    {
        len++;
        cur = cur->next;
    }
    return len;
}

// 查找两个链表的第一个公共节点
// ListNode *FindFirstCommonNode(ListNode *pHead1, ListNode *pHead2)
// {
//     if (pHead1 == nullptr || pHead2 == nullptr)
//         return nullptr;

//     // 计算两个链表的长度
//     int len1 = GetListLength(pHead1);
//     int len2 = GetListLength(pHead2);

//     ListNode *p1 = pHead1->next; // 跳过头节点
//     ListNode *p2 = pHead2->next; // 跳过头节点
//     // 让较长的链表先走差值步
//     if (len1 > len2)
//     {
//         for (int i = 0; i < len1 - len2; i++)
//             p1 = p1->next;
//     }
//     else
//     {
//         for (int i = 0; i < len2 - len1; i++)
//         {
//             p2 = p2->next;
//         }
//     }

//     // 同时移动两个指针，直到找到第一个公共节点
//     while (p1 != nullptr && p2 != nullptr)
//     {
//         if (p1 == p2)
//         {
//             // 找到公共节点
//             return p1;
//         }
//         p1 = p1->next;
//         p2 = p2->next;
//     }

//     return nullptr;
// }

/*
情况一：两个链表相交
链表 headA 和 headB 的长度分别是 m 和 n。假设链表 headA 的不相交部分有 a 个节点，链表 headB 的不相交部分有 b 个节点，两个链表相交的部分有 c 个节点，则有 a+c=m，b+c=n。
如果 a==b，则两个指针会同时到达两个链表相交的节点，此时返回相交的节点；
如果 a!=b，则指针 pA 会遍历完链表 headA，指针 pB 会遍历完链表 headB，两个指针不会同时到达链表的尾节点，然后指针 pA 移到链表 headB 的头节点，指针 pB 移到链表 headA 的头节点，然后两个指针继续移动，
在指针 pA 移动了 a+c+b 次、指针 pB 移动了 b+c+a 次之后，两个指针会同时到达两个链表相交的节点，该节点也是两个指针第一次同时指向的节点，此时返回相交的节点。

情况二：两个链表不相交
链表 headA 和 headB 的长度分别是 m 和 n。考虑当 m=n 和 m!=n 时，两个指针分别会如何移动：
如果 m==n，则两个指针会同时到达两个链表的尾节点，然后同时变成空值 null，此时返回 null；
如果 m!=n，则由于两个链表没有公共节点，两个指针也不会同时到达两个链表的尾节点，因此两个指针都会遍历完两个链表，在指针 pA 移动了 m+n 次、指针 pB 移动了 n+m 次之后，两个指针会同时变成空值 null，此时返回 null。
*/

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

    ListNode *result = FindFirstCommonNode(headA, headB);
    if (result != nullptr)
    {
        cout << "Common node value: " << result->data << endl;
    }
    else
    {
        cout << "No common node found" << endl;
    }

    return 0;
}
