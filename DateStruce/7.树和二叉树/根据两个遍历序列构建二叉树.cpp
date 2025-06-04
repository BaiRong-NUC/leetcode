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

// 获取树的前序序列
vector<ElemType> preorderDisplay(TreeNode *root)
{
    vector<ElemType> res;
    stack<TreeNode *> s;
    while (!s.empty() || root != nullptr)
    {
        while (root != nullptr)
        {
            res.push_back(root->data);
            s.push(root);
            root = root->left;
        }
        root = s.top();
        s.pop();
        root = root->right;
    }
    return res;
}
// 获取树的中序序列
vector<ElemType> inorderDisplay(TreeNode *root)
{
    vector<ElemType> res;
    stack<TreeNode *> s;
    while (!s.empty() || root != nullptr)
    {
        while (root != nullptr)
        {
            s.push(root);
            root = root->left;
        }
        root = s.top();
        s.pop();
        res.push_back(root->data);
        root = root->right;
    }
    return res;
}
// 获取树的后序序列
vector<ElemType> postorderDisplay(TreeNode *root)
{
    vector<ElemType> res;
    stack<TreeNode *> s;
    TreeNode *prev = nullptr;
    while (!s.empty() || root != nullptr)
    {
        while (root != nullptr)
        {
            s.push(root);
            root = root->left;
        }
        root = s.top();
        s.pop();
        if (root->right == nullptr || root->right == prev)
        {
            res.push_back(root->data);
            prev = root;
            root = nullptr;
        }
        else
        {
            s.push(root);
            root = root->right;
        }
    }
    return res;
}

TreeNode *buildTreeHelper(vector<ElemType> &preorder, int preStart, int preEnd,
                          vector<ElemType> &inorder, int inStart, int inEnd)
{
    if (preStart > preEnd || inStart > inEnd)
        return nullptr;

    // 前序遍历的第一个元素是根节点
    TreeNode *root = new TreeNode(preorder[preStart]);

    // 在中序遍历中查找根节点的位置
    int inRoot = inStart;
    while (inRoot <= inEnd && inorder[inRoot] != root->data)
    {
        inRoot++;
    }

    int numsLeft = inRoot - inStart;

    // 递归构建左子树和右子树
    root->left = buildTreeHelper(preorder, preStart + 1, preStart + numsLeft,
                                 inorder, inStart, inRoot - 1);
    root->right = buildTreeHelper(preorder, preStart + numsLeft + 1, preEnd,
                                  inorder, inRoot + 1, inEnd);

    return root;
}

TreeNode *buildTreeFromPreIn(vector<ElemType> &preorder, vector<ElemType> &inorder)
{
    if (preorder.empty() || inorder.empty())
        return nullptr;
    return buildTreeHelper(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
}

TreeNode *buildTreeHelperInPost(vector<ElemType> &inorder, int inStart, int inEnd,
                                vector<ElemType> &postorder, int postStart, int postEnd)
{
    if (inStart > inEnd || postStart > postEnd)
    {
        return nullptr;
    }
    // 后序遍历的最后一个元素是根节点
    TreeNode *root = new TreeNode(postorder[postEnd]);

    // 在中序遍历中查找根节点的位置
    int inRoot = inStart;
    while (inRoot <= inEnd && inorder[inRoot] != root->data)
    {
        inRoot++;
    }

    int numsLeft = inRoot - inStart;

    // 递归构建左子树和右子树
    root->left = buildTreeHelperInPost(inorder, inStart, inRoot - 1, postorder, postStart, postStart + numsLeft - 1);
    root->right = buildTreeHelperInPost(inorder, inRoot + 1, inEnd, postorder, postStart + numsLeft, postEnd - 1);

    return root;
}

TreeNode *buildTreeFromInPost(vector<ElemType> &inorder, vector<ElemType> &postorder)
{
    if (inorder.empty() || postorder.empty())
        return nullptr;
    return buildTreeHelperInPost(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
}

int main(int argc, char const *argv[])
{
    vector<ElemType> data = {1, 3, 2, -1, 4, 5};
    TreeNode *root = CreatTreeByArray(data);
    cout << "原二叉树:" << endl;
    printTree(root);
    vector<ElemType> preorder = preorderDisplay(root);
    vector<ElemType> inorder = inorderDisplay(root);
    vector<ElemType> postorder = postorderDisplay(root);
    // 构建二叉树,使用前序和中序构建二叉树
    cout << "使用前序和中序构建二叉树:" << endl;
    TreeNode *newRoot = buildTreeFromPreIn(preorder, inorder);
    printTree(newRoot);
    // 构建二叉树,使用中序和后序构建二叉树
    cout << "使用中序和后序构建二叉树:" << endl;
    TreeNode *newRoot2 = buildTreeFromInPost(inorder, postorder);
    printTree(newRoot2);
    return 0;
}
