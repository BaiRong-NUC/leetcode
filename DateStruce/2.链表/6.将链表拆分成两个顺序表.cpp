// 06. 设C=(a1,b1,a2,b2,…,am,bn)为线性表，采用带头结点的单链表存放，设计一个就地算法将其拆分为两个线性表
// 使得A={a1，a2,...,am},B={b1,b2...bn}。
#include <iostream>
#include <vector>
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

// 拆分链表
void SplitListNode(ListNode *head, vector<ElemType> &left, vector<ElemType> &right)
{
    // 指向第一个有效元素
    ListNode *cur = head->next;
    int pos = 0;
    // 如果left.size()==0 只能用push_back 如果left.size()!=0 left[1]
    while (cur != nullptr)
    {
        if (pos % 2 == 0)
        {
            // 偶数放left
            left.push_back(cur->data);
        }
        else
        {
            // 奇数right
            right.push_back(cur->data);
        }
        pos += 1;
        cur = cur->next;
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
void PrintVector(const vector<ElemType> &vet)
{
    if (vet.size() == 0)
    {
        cout << "顺序表为空" << endl;
        return;
    }
    for (int i = 0; i < vet.size(); i++)
    {
        cout << vet[i] << " ";
    }
    cout << "\n";
}
int main(int argc, char const *argv[])
{
    int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // int array[1] = {10};

    ListNode *head = CreatListNodeByArray(array, sizeof(array) / sizeof(ElemType));
    PrintListNode(head);
    vector<ElemType> left;
    vector<ElemType> right;
    SplitListNode(head, left, right);
    PrintVector(left);
    PrintVector(right);
    return 0;
}