/*
 * @lc app=leetcode.cn id=547 lang=cpp
 *
 * [547] 省份数量
 */

#include <vector>

using namespace std;

/**
Accepted
113/113 cases passed (16 ms)
Your runtime beats 93.36 % of cpp submissions
Your memory usage beats 68.75 % of cpp submissions (13.3 MB)
 */

// @lc code=start
// 并查集思路
class UnionSet
{
    vector<int> ufs;

public:
    UnionSet(size_t size)
    {
        ufs.resize(size, -1);
    }
    // 找某个节点的根节点
    int findRoot(int val)
    {
        int ret = 0;
        while (val >= 0)
        {
            ret = val;
            val = ufs[val];
        }
        return ret;
    }
    // 两个并查集结合
    void unionSet(int left, int right)
    {
        int left_root = findRoot(left);
        int right_root = findRoot(right);
        if (left_root != right_root)
        {
            ufs[left_root] += ufs[right_root];
            ufs[right_root] = left_root;
        }
    }

    // 返回并查集中集合个数
    size_t unionSize()
    {
        int ret = 0;
        for (int i = 0; i < ufs.size(); i++)
        {
            if (ufs[i] < 0)
            {
                ret += 1;
            }
        }
        return ret;
    }
};
class Solution
{
public:
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        UnionSet set(isConnected.size());
        for (int i = 0; i < isConnected.size(); i++)
        {
            for (int j = 0; j < isConnected[i].size(); j++)
            {
                if (isConnected[i][j] == 1)
                {
                    set.unionSet(i, j);
                }
            }
        }
        return set.unionSize();
    }
};
// @lc code=end
