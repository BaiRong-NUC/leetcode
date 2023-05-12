/*
 * @lc app=leetcode.cn id=1129 lang=cpp
 *
 * [1129] 颜色交替的最短路径
 */

#include <vector>
#include <queue>
#include <iostream>

using namespace std;

// @lc code=start
class Solution
{
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>> &redEdges, vector<vector<int>> &blueEdges)
    {
        // 将红色，蓝色的边保存到临界表中
        vector<vector<int>> redEdge(n);
        vector<vector<int>> blueEdge(n);
        for (vector<int> &edge : redEdges)
        {
            redEdge[edge[0]].push_back(edge[1]);
        }
        for (vector<int> &edge : blueEdges)
        {
            blueEdge[edge[0]].push_back(edge[1]);
        }

        vector<int> redAns(n, INT_MAX);  // 最后一步为 [红色] 时到达点i的 [最小] 步数
        vector<int> blueAns(n, INT_MAX); // 最后一步为 [蓝色] 时到达点i的 [最小] 步数
        // 点[0] 到 [点0] 需要 [0] 步
        redAns[0] = blueAns[0] = 0;

        // pair<node,color> 0是下一次选红色，1是下一次选蓝色
        queue<pair<int, int>> q;
        // 一开始可以选择蓝色或红色
        q.push(make_pair(0, 0));
        q.push(make_pair(0, 1));

        int level = 0; // bfs层数，路径长度
        while (!q.empty())
        {
            level += 1;
            int size = q.size(); // 这一层的大小
            for (int i = 0; i < size; i++)
            {
                auto msg = q.front();
                q.pop();
                int beginPos = msg.first;
                int color = msg.second;
                if (color == 0)
                {
                    // 下一步选红色，从红色邻接表找可以走到下一点
                    for (int nextPos : redEdge[beginPos])
                    {
                        if (level < redAns[nextPos])
                        {
                            redAns[nextPos] = level;
                            q.push(make_pair(nextPos, 1)); // 下一次走nextPos节点，颜色选蓝色
                        }
                    }
                }
                else
                {
                    // 下一次选择蓝色
                    for (int nextPos : blueEdge[beginPos])
                    {
                        if (level < blueAns[nextPos])
                        {
                            blueAns[nextPos] = level;
                            q.push(make_pair(nextPos, 0));
                        }
                    }
                }
            }
        }

        // 到达这个位置的最小步数是红色结尾和蓝色结尾最小的步数
        for (int i = 0; i < redAns.size(); i++)
        {
            if (blueAns[i] < redAns[i])
            {
                redAns[i] = blueAns[i];
            }
            else if (redAns[i] == INT_MAX)
            {
                redAns[i] = -1;
            }
        }
        return redAns;
    }
};
// @lc code=end
