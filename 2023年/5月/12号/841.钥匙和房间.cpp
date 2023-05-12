/*
 * @lc app=leetcode.cn id=841 lang=cpp
 *
 * [841] 钥匙和房间
 */

#include <vector>

using namespace std;

/**
Accepted
68/68 cases passed (4 ms)
Your runtime beats 98.79 % of cpp submissions
Your memory usage beats 90.1 % of cpp submissions (10 MB)
 */

// @lc code=start
class Solution
{
    void dfs(vector<vector<int>> &rooms, vector<bool> &visit, int &ret, int pos)
    {
        visit[pos] = true;
        ret += 1;
        for (int i = 0; i < rooms[pos].size(); i++)
        {
            if (visit[rooms[pos][i]] == false)
            {
                dfs(rooms, visit, ret, rooms[pos][i]);
            }
        }
    }

public:
    bool canVisitAllRooms(vector<vector<int>> &rooms)
    {
        // dfs遍历
        vector<bool> visit(rooms.size(), false);
        int count = 0;
        dfs(rooms, visit, count, 0);
        return count == rooms.size();
    }
};
// @lc code=end
