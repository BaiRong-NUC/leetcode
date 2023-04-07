/*
 * @lc app=leetcode.cn id=1128 lang=cpp
 *
 * [1128] 等价多米诺骨牌对的数量
 */

#include <vector>
#include <algorithm>
#include <assert.h>

using namespace std;

// @lc code=start

// 并查集
class UF
{
public:
    vector<int> parent;
    vector<int> size;
    unordered_set<int> root;
    int n;
    UF(int _n) : n(_n), parent(_n), size(_n, 0)
    {
        iota(parent.begin(), parent.end(), 0);
        for (int i = 1; i <= 9; i++)
        {
            for (int j = 1; j <= 9; j++)
            {
                int idx1 = 10 * i + j;
                int idx2 = 10 * j + i;
                idx1 = find(idx1);
                idx2 = find(idx2);
                if (idx1 == idx2)
                    continue;
                parent[idx1] = idx2;
            }
        }
        for (int i = 0; i < 100; i++)
            root.insert(parent[i]);
    }
    int find(int x)
    {
        return x == parent[x] ? x : parent[x] = find(parent[x]);
    }
    void insert(vector<int> &v)
    {
        int idx = 10 * v[0] + v[1];
        size[find(idx)]++;
    }
    int getAns()
    {
        int ans = 0;
        for (auto &ele : root)
            ans += size[ele] * (size[ele] - 1) / 2;
        return ans;
    }
};

class Solution
{
public:
    bool isEquivalent(vector<int> &v1, vector<int> &v2)
    {
        return (v1[0] == v2[0] && v1[1] == v2[1]) || (v1[0] == v2[1] && v1[1] == v2[0]);
    }
    int numEquivDominoPairs(vector<vector<int>> &dominoes)
    {
        int n = dominoes.size();
        UF uf(10 * 10);
        for (auto &v : dominoes)
        {
            uf.insert(v);
        }
        return uf.getAns();
    }
};

// O(N^2)超时
//  class Solution
//  {
//      bool Match(vector<int> &left, vector<int> &right)
//      {
//          bool match = false;
//          if ((left[0] == right[0] && left[1] == right[1]) || (left[0] == right[1] && left[1] == right[0]))
//          {
//              match = true;
//          }
//          return match;
//      }

// public:
//     int numEquivDominoPairs(vector<vector<int>> &dominoes)
//     {
//         int ret = 0;
//         for (int i = 0; i < dominoes.size(); i++)
//         {
//             for (int j = i + 1; j < dominoes.size(); j++)
//             {
//                 if (Match(dominoes[i], dominoes[j]))
//                 {
//                     ret += 1;
//                 }
//             }
//         }
//         return ret;
//     }
// };
// @lc code=end
