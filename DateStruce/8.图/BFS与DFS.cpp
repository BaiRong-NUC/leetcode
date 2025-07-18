#include "Graph.h"
#include <queue>

// 图的BFS遍历
void BFS(Graph &graph, vector<bool> &visited, char beginChar)
{
    int beginPos = graph.charToInt[beginChar];
    int size = graph.adjMatrix.size();
    queue<int> q;
    q.push(beginPos);
    visited[beginPos] = true;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        // 输出当前顶点字符
        cout << graph.intToChar[u] << " ";
        // 遍历邻接点
        for (int v = 0; v < size; v++)
        {
            if (graph.adjMatrix[u][v] && !visited[v])
            {
                q.push(v);
                visited[v] = true;
            }
        }
    }
}
void BFS(Graph &graph, char beginChar)
{
    int size = graph.adjMatrix.size();
    vector<bool> visited(size, false);
    BFS(graph, visited, beginChar);
    // 如果有未访问的点，递归遍历其它连通分量
    for (int i = 0; i < size; i++)
    {
        if (visited[i] == false)
        {
            // 非连通图
            BFS(graph, visited, graph.intToChar[i]);
        }
    }
}

// 图的DFS遍历
void DFS(Graph &graph, vector<bool> &visited, char beginChar)
{
    int u = graph.charToInt[beginChar];
    cout << graph.intToChar[u] << " ";
    visited[u] = true;
    int size = graph.adjMatrix.size();
    for (int v = 0; v < size; v++)
    {
        if (graph.adjMatrix[u][v] && !visited[v])
        {
            DFS(graph, visited, graph.intToChar[v]);
        }
    }
}

void DFS(Graph &graph, char beginChar)
{
    int size = graph.adjMatrix.size();
    vector<bool> visited(size, false);
    DFS(graph, visited, beginChar);
    // 如果有未访问的点，递归遍历其它连通分量
    for (int i = 0; i < size; i++)
    {
        if (!visited[i])
        {
            DFS(graph, visited, graph.intToChar[i]);
        }
    }
}

int main(int argc, char const *argv[])
{
    Graph graph({'A', 'B', 'C', 'D', 'E'}, false);
    graph.addEdge('A', 'B');
    graph.addEdge('A', 'D');
    graph.addEdge('B', 'C');
    graph.addEdge('D', 'C');
    graph.printAdjMatrix();
    cout << "BFS遍历: ";
    BFS(graph, 'E');
    cout << endl;
    cout << "DFS遍历: ";
    DFS(graph, 'A');
    return 0;
}
