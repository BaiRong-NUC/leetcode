#include <iostream>
#include <stack>
#include <vector>
#include <queue>
using namespace std;
typedef int ElemType;
// 二叉树节点的定义
typedef struct TreeNode
{
    ElemType data;
    struct TreeNode *left;
    struct TreeNode *right;
    bool ltag = false; // 左孩子是否线索化
    bool rtag = false; // 右孩子是否线索化
    TreeNode(ElemType x) : data(x), left(nullptr), right(nullptr) {}
} TreeNode;

// 重点:层序构造二叉树,如果节点为空,则用-1表示
TreeNode *CreatTreeByArray(vector<ElemType> &data)
{
    if (data.size() == 0 || data[0] == -1)
        return nullptr;
    TreeNode *root = (TreeNode *)malloc(sizeof(TreeNode));
    root->data = data[0];
    queue<TreeNode *> q; // 队列,用来存储节点
    q.push(root);        // 先把根节点入队
    int pos = 1;         // 用来遍历数组
    while (!q.empty() && pos < data.size())
    {
        TreeNode *cur = q.front();
        q.pop();
        // pos这个位置就是cur的子节点,先左后右
        if (data[pos] != -1)
        {
            // 左孩子有效
            cur->left = new TreeNode(data[pos]);
            cur->left->data = data[pos];
            q.push(cur->left);
        }
        pos += 1;
        if (pos < data.size() && data[pos] != -1)
        {
            // 右孩子有效
            cur->right = new TreeNode(data[pos]);
            cur->right->data = data[pos];
            q.push(cur->right);
        }
        pos += 1;
    }
    return root;
}
int deep(TreeNode *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    int left = deep(root->left);
    int right = deep(root->right);
    return max(left, right) + 1;
}
// 打印二叉树, 不要求掌握
void dfs(TreeNode *root, vector<vector<string>> &ret, int row, int col, const int &deep)
{
    if (root == nullptr)
    {
        return;
    }
    ret[row][col] = to_string(root->data);
    if (root->left != nullptr)
        dfs(root->left, ret, row + 1, col - (1 << (deep - row - 1)), deep);
    if (root->right != nullptr)
        dfs(root->right, ret, row + 1, col + (1 << (deep - row - 1)), deep);
}
void printTree(TreeNode *root)
{
    int tree_deep = deep(root) - 1; // 根节点高度为0
    int row = tree_deep + 1;
    int col = (1 << row) - 1;
    vector<vector<string>> ret(row, vector<string>(col, " "));
    dfs(root, ret, 0, (col - 1) / 2, tree_deep);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << ret[i][j];
        }
        cout << endl;
    }
}

// 1 中序线索化二叉树
void InOrderThreading(TreeNode *root)
{
    stack<TreeNode *> st;
    TreeNode *prev = nullptr; // 用来记录上一个访问的节点
    while (!st.empty() || root != nullptr)
    {
        while (root != nullptr)
        {
            st.push(root);
            root = root->left;
        }
        root = st.top();
        st.pop();
        // 处理当前节点
        if (root->left == nullptr)
        {
            root->ltag = true; // 左孩子为空,线索化
            root->left = prev; // 左孩子指向prev
        }
        if (prev != nullptr && prev->right == nullptr)
        {
            prev->rtag = true;  // 右孩子为空,线索化
            prev->right = root; // 右孩子指向root
        }
        prev = root; // 更新prev
        root = root->right;
    }
}
TreeNode *getNextNodeInorder(TreeNode *node)
{
    if (node->rtag == true) // 右孩子是线索化的
    {
        return node->right; // 直接返回右孩子
    }
    else // 右孩子不是线索化的
    {
        // 找右子树的最左下的节点
        node = node->right;
        while (node != nullptr && node->ltag == false)
        {
            node = node->left;
        }
        return node;
    }
}
// 中序线索化二叉树的遍历
void InOrderThreadingDisplay(TreeNode *root)
{
    if (root == nullptr)
        return;

    // 找最左下的节点
    while (root->ltag == false)
    {
        root = root->left;
    }
    // 打印第一个出现的节点
    cout << root->data << " ";
    while (root->right != nullptr)
    {
        root = getNextNodeInorder(root);
        cout << root->data << " ";
    }
}

// 2 前序线索化二叉树
void PreOrderThreading(TreeNode *root)
{
    stack<TreeNode *> st;
    TreeNode *prev = nullptr;
    if (root != nullptr)
    {
        st.push(root);
    }
    while (!st.empty())
    {
        TreeNode *curr = st.top();
        st.pop();

        // 处理当前节点
        if (curr->left == nullptr)
        {
            curr->ltag = true;
            curr->left = prev;
        }

        if (prev != nullptr && prev->right == nullptr)
        {
            prev->rtag = true;
            prev->right = curr;
        }

        prev = curr;

        // 先压入右子树，再压入左子树
        if (curr->rtag == false && curr->right != nullptr)
        {
            st.push(curr->right);
        }
        if (curr->ltag == false && curr->left != nullptr)
        {
            st.push(curr->left);
        }
    }
}

TreeNode *getNextNodePreorder(TreeNode *node)
{
    if (node->rtag == true)
    {                       // 右孩子是线索化的
        return node->right; // 直接返回右孩子
    }
    else
    {
        if (node->ltag == false && node->left != nullptr) // 左孩子不是线索化的,且左孩子不为空
            return node->left;

        // 找右子树的最左下的节点
        node = node->right;
        while (node != nullptr && node->ltag == false)
        {
            node = node->left;
        }
        return node;
    }
}

// 前序线索二叉树的遍历
void PreOrderThreadingDisplay(TreeNode *root)
{
    if (root == nullptr)
        return;

    // 打印第一个出现的节点
    cout << root->data << " ";
    while (root->right != nullptr)
    {
        root = getNextNodePreorder(root);
        cout << root->data << " ";
    }
}
// 3 后序线索化二叉树
void PostOrderThreading(TreeNode *root)
{
    stack<TreeNode *> st;
    TreeNode *prev = nullptr;
    TreeNode *prevThreading = nullptr;
    while (!st.empty() || root != nullptr)
    {
        while (root != nullptr)
        {
            st.push(root);
            root = root->left;
        }
        root = st.top();
        st.pop();
        if (root->right == nullptr || root->right == prev) // 右孩子为空或者右孩子已经访问过
        {
            // 处理当前节点
            if (root->left == nullptr)
            {
                root->ltag = true;          // 左孩子为空,线索化
                root->left = prevThreading; // 左孩子指向prev
            }
            if (prevThreading != nullptr && prevThreading->right == nullptr)
            {
                prevThreading->rtag = true;  // 右孩子为空,线索化
                prevThreading->right = root; // 右孩子指向root
            }
            prevThreading = root; // 更新prevThreading
            prev = root;          // 更新prev
            root = nullptr;       // 置空root,防止再次访问右孩子
        }
        else
        {
            st.push(root); // 右孩子不为空,且右孩子没有访问过,将root入栈
            root = root->right;
        }
    }
}
// 后序线索化二叉树的遍历
// 采用根右左的顺序遍历,然后逆序输出
TreeNode *getNextNodePostorder(TreeNode *node)
{
    if (node->ltag == true)
    {
        return node->left;
    }
    else
    {
        // node->ltag==false有左子树
        if (node->right != nullptr && node->rtag == false)
        {
            // 左子树右子树都有,向右边走
            return node->right;
        }
        else
        {
            // 没有右树,向左边走
            return node->left;
        }
    }
}
void PostOrderThreadingDisplay(TreeNode *root)
{
    if (root == nullptr)
        return;
    stack<TreeNode *> st;
    while (root != nullptr)
    {
        st.push(root);
        root = getNextNodePostorder(root);
    }
    // 逆序打印
    while (!st.empty())
    {
        cout << st.top()->data << " ";
        st.pop();
    }
    cout << "\n";
}

int main(int argc, char const *argv[])
{
    vector<ElemType> data = {1, 3, 2, -1, 4, 5};
    TreeNode *root = CreatTreeByArray(data);
    printTree(root);
    cout << endl;
    // cout << "中序线索化二叉树" << endl;
    // InOrderThreading(root);
    // InOrderThreadingDisplay(root);
    // cout << endl;
    // cout << "前序线索化二叉树" << endl;
    // PreOrderThreading(root);
    // PreOrderThreadingDisplay(root);
    // cout << endl;
    cout << "后序线索化二叉树" << endl;
    PostOrderThreading(root);
    PostOrderThreadingDisplay(root);
    return 0;
}
