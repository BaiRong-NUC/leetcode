#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
typedef struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
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
    ret[row][col] = to_string(root->val);
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

// 层序构建二叉树,元素为-1时表示该节点为空
TreeNode *buildTree(const vector<int> &nums)
{
    if (nums.empty() || nums[0] == -1)
        return nullptr;
    TreeNode *root = new TreeNode(nums[0]);
    queue<TreeNode *> q;
    q.push(root);
    int pos = 1;
    while (!q.empty() && pos < nums.size())
    {
        TreeNode *current = q.front();
        q.pop();
        if (pos < nums.size() && nums[pos] != -1)
        {
            current->left = new TreeNode(nums[pos]);
        }
        pos++;
        q.push(current->left);
        if (pos < nums.size() && pos < nums.size())
        {
            current->right = new TreeNode(nums[pos]);
            q.push(current->right);
        }
        pos++;
    }
    return root;
}
// 层序遍历二叉树
void levelOrderTraversal(TreeNode *root)
{
    if (root == nullptr)
        return;
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        TreeNode *current = q.front();
        q.pop();
        cout << current->val << " ";

        if (current->left != nullptr)
        {
            q.push(current->left);
        }
        if (current->right != nullptr)
        {
            q.push(current->right);
        }
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    std::vector<int> nums = {1, 2, 3, 4, 5, -1, 6};
    TreeNode *root = buildTree(nums);
    cout << "构建的二叉树为:" << endl;
    printTree(root);
    cout << "层序遍历结果: ";
    levelOrderTraversal(root);
    return 0;
}
