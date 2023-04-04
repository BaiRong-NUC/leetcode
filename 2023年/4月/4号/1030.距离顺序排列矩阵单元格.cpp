/*
 * @lc app=leetcode.cn id=1030 lang=cpp
 *
 * [1030] 距离顺序排列矩阵单元格
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// @lc code=start
class Solution
{
private:
    int x_dis[4] = {1, 0, 0, -1};
    int y_dis[4] = {0, 1, -1, 0};

public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0)
    {
        vector<vector<int>> ans;
        vector<vector<bool>> visited(R, vector<bool>(C, false));
        visited[r0][c0] = true;
        queue<pair<int, int>> que;
        que.push({r0, c0});
        while (!que.empty())
        {
            int x = que.front().first;
            int y = que.front().second;
            que.pop();
            ans.push_back({x, y});
            for (int i = 0; i < 4; ++i)
            {
                // 如果以前没有访问过
                int nextx = x + x_dis[i];
                int nexty = y + y_dis[i];
                if (nextx < 0 || nexty < 0 || nextx >= R || nexty >= C)
                    continue;
                if (!visited[nextx][nexty])
                {
                    visited[nextx][nexty] = true;
                    que.push({nextx, nexty});
                }
            }
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution solution;
    solution.allCellsDistOrder(2, 2, 0, 1);
    return 0;
}
