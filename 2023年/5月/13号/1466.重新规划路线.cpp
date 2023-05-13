/*
 * @lc app=leetcode.cn id=1466 lang=cpp
 *
 * [1466] 重新规划路线
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/**
执行用时:336 ms 
在所有C++提交中击败了45.90%的用户内存消耗:108.5 MB 
在所有C+＋提交中击败了47.55%的用户通过测试用例:76/76
 */

// @lc code=start
class Solution
{
public:
    int minReorder(int n, vector<vector<int>> &connections)
    {
        vector<vector<pair<int, int>>> edges(n); // 有向图转化无向图(邻接表),pair额外保存权值信息
        for (vector<int> &edge : connections)
        {
            edges[edge[0]].push_back({edge[1], 1});
            edges[edge[1]].push_back({edge[0], 0});
        }
        queue<int> q;
        vector<bool> visit(n, false);
        visit[0] = true;
        q.push(0);
        int ret = 0;
        while (!q.empty())
        {
            int from = q.front();
            q.pop();
            vector<pair<int, int>> adjoin = edges[from];
            for (int i = 0; i < adjoin.size(); i++)
            {
                if (visit[adjoin[i].first] == false)
                {
                    ret += adjoin[i].second;
                    visit[adjoin[i].first] = true;
                    q.push(adjoin[i].first);
                }
            }
        }
        return ret;
    }
};
// @lc code=end
