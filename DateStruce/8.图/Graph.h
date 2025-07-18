#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// 图的邻接矩阵存储
class Graph
{
public:
    // 传入的数组为顶点的值
    Graph(const vector<char> &vertices, bool isDirected = false)
    {
        this->vertices = vertices.size();
        this->adjMatrix.resize(this->vertices, vector<int>(this->vertices, 0));
        for (int i = 0; i < this->vertices; i++)
        {
            this->charToInt[vertices[i]] = i;
            this->intToChar[i] = vertices[i];
        }
        this->isDirected = isDirected;
    }
    // 添加边
    void addEdge(char u, char v)
    {
        if (charToInt.find(u) != charToInt.end() && charToInt.find(v) != charToInt.end())
        {
            int uIndex = charToInt[u];
            int vIndex = charToInt[v];
            this->adjMatrix[uIndex][vIndex] = 1;
            if (this->isDirected == false)
            {
                // 无向图
                this->adjMatrix[vIndex][uIndex] = 1;
            }
        }
        else
        {
            cout << "顶点不存在" << endl;
        }
    }
    void printAdjMatrix()
    {
        for (int i = 0; i < vertices; i++)
        {
            for (int j = 0; j < vertices; j++)
            {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    int vertices;                       // 顶点数量
    vector<vector<int>> adjMatrix;      // 邻接矩阵
    unordered_map<int, char> intToChar; // 索引到顶点的映射
    unordered_map<char, int> charToInt; // 顶点到做因的映射
    bool isDirected;                    // 是否是有向图
};
