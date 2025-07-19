#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
typedef int ElemType;
typedef struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : data(x), left(nullptr), right(nullptr) {}
} TreeNode;

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
/**
 * 根节点 需要放置在 顶行 的 正中间 ，对应位置为 res[0][(n-1)/2] 。
 * 对于放置在矩阵中的每个节点，设对应位置为 res[r][c] ，将其左子节点放置在 res[r+1][c-2^(height-r-1)] ，右子节点放置在 res[r+1][c+2^(height-r-1)]
 */
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
// 打印二叉树
vector<vector<string>> printTree(TreeNode *root)
{
    int tree_deep = deep(root) - 1; // 根节点高度为0
    int row = tree_deep + 1;
    int col = (1 << row) - 1;
    vector<vector<string>> ret(row, vector<string>(col, " "));
    dfs(root, ret, 0, (col - 1) / 2, tree_deep);
    for (int i = 0; i < ret.size(); i++)
    {
        for (int j = 0; j < ret[i].size(); j++)
        {
            cout << ret[i][j];
        }
        cout << endl;
    }
    return ret;
}

// BST树的删除
TreeNode *deleteBSTtree(TreeNode *&root, ElemType value)
{
    if (root == nullptr)
    {
        return nullptr;
    }
    // 找到删除这个节点的位置
    if (root->data > value)
    {
        root->left = deleteBSTtree(root->left, value);
    }
    else if (root->data < value)
    {
        root->right = deleteBSTtree(root->right, value);
    }
    else
    {
        // 找到了要删除的节点
        if (root->left == nullptr)
        {
            return root->right;
        }
        else if (root->right == nullptr)
        {
            return root->left;
        }
        else
        {
            // 找右子树的最小值
            TreeNode *minNode = root->right;
            while (minNode->left != nullptr)
            {
                minNode = minNode->left;
            }
            // 将minNode的值赋给当前节点
            root->data = minNode->data;                              // newNode一定是左子树为空
            root->right = deleteBSTtree(root->right, minNode->data); // 删除右子树中的最小值
            delete minNode;
        }
    }
    return root; // 返回当前节点
}

// BST树的插入
void insertBSTtree(TreeNode *&root, ElemType data)
{
    if (root == nullptr)
    {
        root = new TreeNode(data);
        return;
    }
    else
    {
        TreeNode *cur = root;     // 用来遍历树
        TreeNode *prev = nullptr; // 用来记录父节点
        while (cur != nullptr)
        {
            prev = cur;
            if (data < cur->data)
            {
                cur = cur->left;
            }
            else if (data > cur->data)
            {
                cur = cur->right;
            }
            else
            {
                // 值相同,不存在这种情况,直接返回
                return;
            }
        }
        // 找到插入的位置,prev只想当前要插入节点的父节点
        if (prev->data > data)
        {
            prev->left = new TreeNode(data);
        }
        else
        {
            prev->right = new TreeNode(data);
        }
    }
}
//  根据数组构造BST树
TreeNode *createBSTtree(vector<ElemType> &data)
{
    TreeNode *root = nullptr;
    for (int i = 0; i < data.size(); i++)
    {
        insertBSTtree(root, data[i]);
    }
    return root;
}

int main(int argc, char const *argv[])
{
    vector<ElemType> data = {5, 3, 7, 2, 4, 6};
    TreeNode *root = createBSTtree(data);
    printTree(root);
    cout << "删除节点3后:" << endl;
    deleteBSTtree(root, 3);
    printTree(root);
    return 0;
}
