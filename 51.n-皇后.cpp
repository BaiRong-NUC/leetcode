/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */
#include <vector>
#include <string>
#include <iostream>
using namespace std;
// @lc code=start
class Solution
{
    vector<vector<string>> ret; // 保存所有可能的结果
public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<string> board(n, string(n, '.')); // 初始化棋盘,保存其中一种可能结果
        backtrack(board, 0);                     // 从第0行开始回溯，在回溯的过程中，会将所有可能的结果保存到ret中
        return ret;
    }
    void backtrack(vector<string> &board, int row)
    {
        // cout << "row: " << row << endl;
        if (row == board.size())
        {
            // 说明已经找到了一种可能的结果，将其保存到ret中
            // cout << "debug" << endl;
            ret.push_back(board);
            return;
        }
        // 遍历当前行的所有列,并作选择
        for (int col = 0; col < board[row].size(); col++)
        {
            if (isVaild(board, row, col))
            {
                // cout << "row: " << row << endl;
                // 做选择
                board[row][col] = 'Q';
                // 进入下一行决策树
                backtrack(board, row + 1);
                // 撤销选择
                board[row][col] = '.';
            }
        }
    }

    bool isVaild(vector<string> &board, int row, int col)
    {
        // 检查列是否有皇后互相冲突
        for (int i = 0; i < row; i++)
        {
            if (board[i][col] == 'Q')
            {
                return false;
            }
        }
        // 检查右上方是否有皇后互相冲突
        for (int i = row - 1, j = col + 1; i >= 0 && j < board[row].size(); i--, j++)
        {
            if (board[i][j] == 'Q'){
                return false;
            }
        }
        //检查左上方是否有皇后互相冲突
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        {
            if (board[i][j] == 'Q'){
                return false;
            }
        }
        //因为递归是按照行从上向下的，每一行选择一个皇后后进入下一行，所以不需要考虑行是否有皇后互相冲突
        //同理，不需要考虑board[row][col]下面的列元素，和右下方，左下方的元素是否冲突，因为一定是不冲突的、
        return true;
    }
};
// @lc code=end

//调试代码
int main(int argc, char const *argv[])
{
    Solution s;
    s.solveNQueens(4);
    return 0;
}
