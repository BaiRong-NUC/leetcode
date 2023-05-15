/*
 * @lc app=leetcode.cn id=1926 lang=cpp
 *
 * [1926] 迷宫中离入口最近的出口
 */

#include <vector>
#include <queue>

using namespace std;

/**
执行用时:96 ms ,在所有C++提交中击败了 91.97%的用户
内存消耗:30.1 MB ，在所有C++提交中击败了34.47%的用户
通过测试用例:194/ 194
 */

// @lc code=start
class Solution
{
    vector<vector<int>> dict{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

public:
    int nearestExit(vector<vector<char>> &maze, vector<int> &entrance)
    {
        int step = 0;
        int row = maze.size();
        int col = maze[0].size();
        vector<vector<bool>> visit(row, vector<bool>(col, false));
        // bfs先遍历到出口一定是最小步骤
        queue<pair<int, int>> path;
        path.push(make_pair(entrance[0], entrance[1]));
        visit[entrance[0]][entrance[1]] = true;
        while (!path.empty())
        {
            step += 1;
            int curSize = path.size();
            for (int i = 0; i < curSize; i++)
            {
                pair<int, int> curPos = path.front();
                path.pop();
                // 这个位置走四个方向
                for (int i = 0; i < dict.size(); i++)
                {
                    int next_row = curPos.first + dict[i][0];
                    int next_col = curPos.second + dict[i][1];
                    if (next_row >= 0 && next_row < row && next_col >= 0 && next_col < col && visit[next_row][next_col] == false && maze[next_row][next_col] == '.')
                    {
                        visit[next_row][next_col] = true;
                        if (next_row == 0 || next_row == row - 1 || next_col == 0 || next_col == col - 1)
                        {
                            // 到达出口
                            return step;
                        }
                        path.push(make_pair(next_row, next_col));
                    }
                }
            }
        }
        return -1;
    }
};
// @lc code=end
