/**
 * C++刷题常见头文件包含
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <stack>
#include <queue>
#include <unordered_set>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 二叉树打印函数方便测试
class PrintCur
{
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

public:
    vector<vector<string>> printTree(TreeNode *root)
    {
        int tree_deep = deep(root) - 1; // 根节点高度为0
        int row = tree_deep + 1;
        int col = (1 << row) - 1;
        vector<vector<string>> ret(row, vector<string>(col, ""));
        dfs(root, ret, 0, (col - 1) / 2, tree_deep);
        for (int i = 0; i < ret.size(); i++)
        {
            for (int j = 0; j < ret[i].size(); j++)
            {
                cout << ret[i][j] << " ";
            }
            cout << endl;
        }
        return ret;
    }
    void printVecter(vector<int> &buff)
    {
        for (auto &num : buff)
        {
            cout << num << " ";
        }
        cout << endl;
    }

    void printVecter(vector<vector<int>> &buff)
    {
        for (int row = 0; row < buff.size(); row++)
        {
            for (int col = 0; col < buff[row].size(); col++)
            {
                cout << buff[row][col] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    void printList(ListNode *head)
    {
        while (head != nullptr)
        {
            cout << head->val << " ";
            head = head->next;
        }
        cout << endl;
    }
};