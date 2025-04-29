// 02.试编写在带头结点的单链表工中删除一个最小值结点的高效算法（假设该结点唯一）。
#include <iostream>
typedef int Element;
// 单链表的节点
typedef struct ListNode
{
    Element data;
    struct ListNode *next;
} ListNode;
// 通过数组构建带头单链表
ListNode *buildList(Element array[], int length)
{
    if (length == 0)
        return nullptr;
    ListNode *head = (ListNode *)malloc(sizeof(ListNode));
    ListNode *tail = head;
    for (int i = 0; i < length; i++)
    {
        ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));
        newNode->data = array[i];
        newNode->next = nullptr;
        tail->next = newNode;
        tail = newNode;
    }
    return head;
}

// 打印带头单链表
void printList(ListNode *head)
{
    ListNode *p = head->next;
    if (p == nullptr)
    {
        std::cout << "链表为空" << std::endl;
        return;
    }
    while (p != nullptr)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

// 删除最小值节点
void deleteMin(ListNode *head)
{

    ListNode *cur = head->next;  // 当前遍历的节点
    ListNode *curPrev = head;    // 当前遍历的节点的前一个节点
    ListNode *min = cur;         // 最小值节点
    ListNode *minPrev = curPrev; // 最小值节点的前一个节点
    while (cur != nullptr)
    {
        if (cur->data < min->data)
        {
            // 更新最小值
            min = cur;
            minPrev = curPrev;
        }
        else
        {
            // 继续遍历
            curPrev = cur;
            cur = cur->next;
        }
    }
    // 找到最小值节点，cur一定为空，min记录最小值，一定不为空
    minPrev->next = min->next; // 删除最小值节点
    free(min);                 // 释放最小值节点的内存
}

int main(int argc, char const *argv[])
{
    Element array[] = {0};
    int length = sizeof(array) / sizeof(array[0]);
    ListNode *head = buildList(array, length);
    printList(head);
    deleteMin(head);
    printList(head);
    return 0;
}