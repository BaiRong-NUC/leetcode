/*
 * @lc app=leetcode.cn id=802 lang=cpp
 *
 * [802] 找到最终的安全状态
 */

#include <vector>
#include <queue>
#include <iostream>

using namespace std;

// @lc code=start
class Solution
{
public:
    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        int size = graph.size();
        // 使用拓扑排序算法求解安全节点,安全节点的出度为0，所以将图反转后求入度为0，就是拓扑排序
        vector<vector<int>> revGraph(size);
        // 节点入度
        vector<int> indegree(size, 0);
        for (int i = 0; i < size; i++)
        {
            for (int adjoin : graph[i])
            {
                revGraph[adjoin].push_back(i);
            }
            indegree[i] = graph[i].size();
        }

        queue<int> q;
        for (int i = 0; i < size; i++)
        {
            // 将入度为0的节点放入队列中
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            // 删除这个节点为起点的有向边,更新入度
            for (int adjoin : revGraph[node])
            {
                indegree[adjoin] -= 1;
                // 如果入度为0，则入队列作为下一次遍历的节点
                if (indegree[adjoin] == 0)
                {
                    q.push(adjoin);
                }
            }
        }

        // 最终入度（原图中出度）为 0 的所有点均为安全点
        vector<int> ret;
        for (int i = 0; i < indegree.size(); i++)
        {
            if (indegree[i] == 0)
            {
                ret.push_back(i);
            }
        }
        return ret;
    }
};
// @lc code=end
