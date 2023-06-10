/*
 * @lc app=leetcode.cn id=427 lang=cpp
 *
 * [427] 建立四叉树
 */

#include <iostream>
#include <vector>
using namespace std;
class Node
{
public:
    bool val;
    bool isLeaf;
    Node *topLeft;
    Node *topRight;
    Node *bottomLeft;
    Node *bottomRight;

    Node()
    {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf)
    {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node *_topLeft, Node *_topRight, Node *_bottomLeft, Node *_bottomRight)
    {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
/*
Accepted
22/22 cases passed (16 ms)
Your runtime beats 51.63 % of cpp submissions
Your memory usage beats 66.67 % of cpp submissions (15.7 MB)
*/
// @lc code=start
// Definition for a QuadTree node.
/*class Node
{
public:
    bool val;
    bool isLeaf;
    Node *topLeft;
    Node *topRight;
    Node *bottomLeft;
    Node *bottomRight;

    Node()
    {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf)
    {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node *_topLeft, Node *_topRight, Node *_bottomLeft, Node *_bottomRight)
    {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/
class Solution
{
public:
    // 辅助函数, 检查正方形内部的值是否全都相同
    bool is_leaf(vector<vector<int>> &grid, int up, int down, int left, int right)
    {
        int t = grid[up][left];
        for (int i = up; i <= down; ++i)
            for (int j = left; j <= right; ++j)
                if (grid[i][j] != t)
                    return false;
        return true;
    }

    // 辅助函数, 递归地构建四叉树
    Node *dfs(vector<vector<int>> &grid, int up, int down, int left, int right)
    {
        // 首先检测能不能作为叶子节点
        if (is_leaf(grid, up, down, left, right))
        {
            // 如果可以作为叶子节点
            return new Node(grid[up][left] == 1, true);
        }

        // 不能作为叶子节点
        int mid_row = (up + down) / 2;
        int mid_col = (left + right) / 2;
        Node *top_left = dfs(grid, up, mid_row, left, mid_col);
        Node *top_right = dfs(grid, up, mid_row, mid_col + 1, right);
        Node *bottom_left = dfs(grid, mid_row + 1, down, left, mid_col);
        Node *bottom_right = dfs(grid, mid_row + 1, down, mid_col + 1, right);
        return new Node(false, false, top_left, top_right, bottom_left, bottom_right);
    }

    Node *construct(vector<vector<int>> &grid)
    {
        return dfs(grid, 0, grid.size() - 1, 0, grid[0].size() - 1);
    }
};
// @lc code=end
