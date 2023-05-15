/*
 * @lc app=leetcode.cn id=797 lang=cpp
 *
 * [797] 所有可能的路径
 */

#include <vector>

using namespace std;

/**
执行用时: 8 ms ，在所有C++提交中击败了 96.46%的用户内存消耗:10.3 MB ，
在所有C+＋提交中击败了95.59%的用户
通过测试用例:30 /30
 */

// @lc code=start
class Solution
{
    vector<int> path = {0};
    void dfs(vector<vector<int>> &graph, vector<vector<int>> &ret, int start, int end)
    {
        if (start == end)
        {
            ret.push_back(path);
            return;
        }
        for (int i = 0; i < graph[start].size(); i++)
        {
            int next = graph[start][i];
            path.push_back(next);
            dfs(graph, ret, next, end);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {
        vector<vector<int>> ret;
        dfs(graph, ret, 0, graph.size() - 1);
        return ret;
    }
};
// @lc code=end
