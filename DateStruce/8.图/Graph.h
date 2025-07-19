#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// 邻接矩阵存储的图
typedef struct Graph
{
    vector<vector<int>> adjMatrix;      // 邻接矩阵
    int numVertices;                    // 顶点数量
    unordered_map<int, char> vertexMap; // 顶点映射，存储顶点编号和字符的对应关系
    unordered_map<char, int> charMap;   // 字符映射，存储字符和顶点编号的对应关系
    bool isDirected;                    // 是否为有向图

    Graph(const vector<char> &vertices, bool isDirected = false)
    {
        numVertices = vertices.size();
        adjMatrix.resize(numVertices, vector<int>(numVertices, 0));
        for (int i = 0; i < numVertices; ++i)
        {
            vertexMap[i] = vertices[i];
            charMap[vertices[i]] = i;
        }
        this->isDirected = isDirected;
    }
    // 添加边
    void addEdge(char from, char to)
    {
        int fromPos = charMap[from];
        int toPos = charMap[to];
        adjMatrix[fromPos][toPos] = 1;
        if (this->isDirected == false)
        {
            adjMatrix[toPos][fromPos] = 1; // 无向图需要双向添加
        }
    }
    // 打印邻接矩阵做测试
    void printAdjMatrix()
    {
        cout << "邻接矩阵：" << endl;
        for (int i = 0; i < numVertices; ++i)
        {
            for (int j = 0; j < numVertices; ++j)
            {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }
} Graph;