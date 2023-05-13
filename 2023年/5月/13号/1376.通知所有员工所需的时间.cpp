/*
 * @lc app=leetcode.cn id=1376 lang=cpp
 *
 * [1376] 通知所有员工所需的时间
 */

#include <vector>
#include <unordered_map>
using namespace std;

/**
Accepted
39/39 cases passed (536 ms)
Your runtime beats 10.86 % of cpp submissions
Your memory usage beats 5.01 % of cpp submissions (166.5 MB)
 */

// @lc code=start
class Solution
{
    void dfs(int mangeId, unordered_map<int, vector<int>> &hash, vector<int> &infoTime, int &ret, int curTime)
    {
        vector<int> people = hash[mangeId];
        if (people.size() == 0)
        {
            ret = max(curTime, ret);
        }
        curTime += infoTime[mangeId];
        for (int i = 0; i < people.size(); i++)
        {
            dfs(people[i], hash, infoTime, ret, curTime);
        }
    }

public:
    int numOfMinutes(int n, int headID, vector<int> &manager, vector<int> &informTime)
    {
        unordered_map<int, vector<int>> _hash; // hash[i]i的下属
        for (int i = 0; i < manager.size(); i++)
        {
            if (i == headID)
            {
                continue;
            }
            _hash[manager[i]].push_back(i);
        }
        int ret = INT_MIN;
        dfs(headID, _hash, informTime, ret, 0);
        return ret;
    }
};
// @lc code=end
