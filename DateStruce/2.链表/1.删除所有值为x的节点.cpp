#include <iostream>
using namespace std;
typedef int ElemType;
typedef struct ListNode
{
    ElemType data;
    struct ListNode *next;
} ListNode;

ListNode *createListNodeByArray(int array[], int length)
{
    ListNode *head = (ListNode *)malloc(sizeof(ListNode));
    ListNode *tail = head;
    for (int i = 0; i < length; i++)
    {
        ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));
        newNode->data = array[i];
        newNode->next = nullptr;
        tail->next = newNode;
        tail = tail->next;
    }
    return head;
}

// 带头
void printList(ListNode *head)
{
    ListNode *cur = head->next;
    if (cur == nullptr)
    {
        cout << "链表为空" << endl;
        return;
    }
    while (cur != nullptr)
    {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << "\n";
}

void delListNumber(ListNode *head, ElemType x)
{
    ListNode *prev = head;
    ListNode *cur = head->next;
    while (cur != nullptr)
    {
        if (cur->data == x)
        {
            // 删除cur这个节点
            prev->next = cur->next;
            free(cur);
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
    int array[] = {1, 1, 1, 1, 1};
    ListNode *head = createListNodeByArray(array, sizeof(array) / sizeof(int));
    printList(head);
    delListNumber(head, 1);
    printList(head);
    return 0;
}