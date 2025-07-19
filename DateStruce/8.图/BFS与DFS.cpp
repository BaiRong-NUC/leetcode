#include "Graph.h"
#include <queue>

void BFS(Graph &graph, char startChar, vector<bool> &visited)
{
    int startPos = graph.charMap[startChar];
    queue<int> que;
    que.push(startPos);
    visited[startPos] = true;
    while (!que.empty())
    {
        int current = que.front();
        que.pop();
        cout << graph.vertexMap[current] << " "; // 打印当前节点
        // 将这个节点的所有未访问的邻接节点加入队列
        for (int i = 0; i < graph.numVertices; i++)
        {
            if (graph.adjMatrix[current][i] == 1 && !visited[i])
            {
                que.push(i);
                visited[i] = true; // 标记为已访问
            }
        }
    }
}
// 图的BFS
void BFS(Graph &graph, char startChar)
{
    vector<bool> visited(graph.numVertices, false);
    BFS(graph, startChar, visited);
    // 处理非连通图没有遍历到的节点
    for (int i = 0; i < graph.numVertices; i++)
    {
        if (visited[i] == false)
        {
            // 非连通图
            BFS(graph, graph.vertexMap[i], visited);
        }
    }
}

void DFS(Graph &graph, char startChar, vector<bool> &visited)
{
    int startPos = graph.charMap[startChar];
    visited[startPos] = true;                 // 标记为已访问
    cout << graph.vertexMap[startPos] << " "; // 打印当前节点
    for (int i = 0; i < graph.numVertices; i++)
    {
        if (graph.adjMatrix[startPos][i] == 1 && !visited[i])
        {
            DFS(graph, graph.vertexMap[i], visited);
        }
    }
}
// 图的DFS
void DFS(Graph &graph, char startChar)
{
    vector<bool> visited(graph.numVertices, false);
    DFS(graph, startChar, visited);
    // 处理非连通图没有遍历到的节点
    for (int i = 0; i < graph.numVertices; i++)
    {
        if (visited[i] == false)
        {
            // 非连通图
            DFS(graph, graph.vertexMap[i], visited);
        }
    }
}
int main(int argc, char const *argv[])
{
    vector<char> vertices = {'A', 'B', 'C', 'D', 'E'};
    Graph graph(vertices, false); // 创建无向图
    graph.addEdge('A', 'B');
    graph.addEdge('B', 'C');
    graph.addEdge('C', 'D');
    graph.addEdge('D', 'A');
    graph.printAdjMatrix();
    cout << "开始BFS遍历：" << endl;
    BFS(graph, 'A');
    cout << endl;
    cout << "开始DFS遍历：" << endl;
    DFS(graph, 'A');
    return 0;
}
