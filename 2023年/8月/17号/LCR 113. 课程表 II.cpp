#include <vector>
#include <queue>
using namespace std;
class Solution
{
private:
    // 存储有向图
    vector<vector<int>> edges;
    // 存储每个节点的入度
    vector<int> inedge;
    // 存储答案
    vector<int> result;

public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        edges.resize(numCourses);
        inedge.resize(numCourses);
        for (const auto &info : prerequisites)
        {
            edges[info[1]].push_back(info[0]);
            // 指向点入度+1 info[1]->info[0]
            inedge[info[0]] += 1;
        }
        queue<int> q;
        // 入度为0的节点放入队列中
        for (int i = 0; i < numCourses; i++)
        {
            if (inedge[i] == 0)
            {
                q.push(i);
            }
        }
        while (!q.empty())
        {
            int val = q.front();
            q.pop();
            result.push_back(val);

            // val指向的节点入度-1
            for (int dst : edges[val])
            {
                inedge[dst] -= 1;
                // 如果相邻节点入度为0.则入队列
                if (inedge[dst] == 0)
                {
                    q.push(dst);
                }
            }
        }
        // 存在环
        if (result.size() != numCourses)
        {
            return {};
        }
        return result;
    }
};