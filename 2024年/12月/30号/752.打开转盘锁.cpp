/*
 * @lc app=leetcode.cn id=752 lang=cpp
 *
 * [752] 打开转盘锁
 */
#include <D:\CppCode\leetcode\global\global.h>
// @lc code=start
class Solution
{
    // 向上拨动锁
    string up(string str, int pos)
    {
        if (str[pos] == '9')
        {
            str[pos] = '0';
        }
        else
        {
            str[pos] += 1;
        }
        return str;
    }
    // 向下拨动锁
    string down(string str, int pos)
    {
        if (str[pos] == '0')
        {
            str[pos] = '9';
        }
        else
        {
            str[pos] -= 1;
        }
        return str;
    }

public:
    // 每次转动都有8种情况，之后在每种情况下再进行讨论
    int openLock(vector<string> &deadends, string target)
    {
        int step = 0;
        // BFS穷举所有可能情况
        queue<string> q;
        // 记录已经穷举过的密码，防止走回头路
        unordered_set<string> visited;
        // 将死亡密码添加到集合中，方便查询
        unordered_set<string> deads;
        for (string dead : deadends)
        {
            deads.insert(dead);
        }
        q.push("0000");
        visited.insert("0000");
        while (!q.empty())
        {
            int size = q.size();
            // 处理队列的所有元素，并将处理结果放回队列中
            for (int i = 0; i < size; i++)
            {
                string key = q.front();
                q.pop();
                // cout << key << endl;
                // 处理当前节点
                if (key == target)
                {
                    return step;
                }
                // 遇到死亡密码，这个密码不应该继续处理
                if (deads.find(key) != deads.end())
                {
                    continue;
                }
                for (int pos = 0; pos < 4; pos++)
                {
                    string up = this->up(key, pos);
                    string down = this->down(key, pos);
                    // 重复元素不添加到队列中
                    if (visited.find(up) == visited.end())
                    {
                        q.push(up);
                        visited.insert(up);
                        // cout << up <<" ";
                    }
                    if (visited.find(down) == visited.end())
                    {
                        q.push(down);
                        visited.insert(down);
                        // cout << down << " ";
                    }
                }
            }
            // cout << endl;
            step += 1;
        }
        return -1;
    }
};
// @lc code=end


int main(int argc, char const *argv[])
{
    Solution sol;
    vector<string> deadends = {"0201", "0101", "0102", "1212", "2002"};
    sol.openLock(deadends, "0202");
    return 0;
}

