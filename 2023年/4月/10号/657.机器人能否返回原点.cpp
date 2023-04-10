/*
 * @lc app=leetcode.cn id=657 lang=cpp
 *
 * [657] 机器人能否返回原点
 */

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution
{
    unordered_map<char, vector<int>> _hash = {
        {'U', {-1, 0}},
        {'D', {1, 0}},
        {'L', {0, 1}},
        {'R', {0, -1}},
    };

public:
    bool judgeCircle(string moves)
    {
        vector<int> begin = {0, 0};
        for (int i = 0; i < moves.size(); i++)
        {
            vector<int> dist = _hash[moves[i]];
            begin[0] += dist[0];
            begin[1] += dist[1];
        }
        return begin[0] == 0 && begin[1] == 0;
    }
};
// @lc code=end
