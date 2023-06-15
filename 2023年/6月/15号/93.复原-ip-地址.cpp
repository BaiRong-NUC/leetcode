/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原 IP 地址
 */

#include <vector>
#include <string>
#include <iostream>
using namespace std;

// @lc code=start
class Solution
{
    static constexpr int SEG_COUNT = 4;

    vector<string> ret;
    vector<int> segments;

    void dfs(const string &s, int segId, int segStart)
    {
        if (segId == SEG_COUNT)
        {
            cout << segStart << endl;
            if (segStart == s.size())
            {
                string ip = "";
                for (int i = 0; i < SEG_COUNT; i++)
                {
                    ip += to_string(segments[i]);
                    if (i != SEG_COUNT - 1)
                    {
                        ip += ".";
                    }
                }
                ret.push_back(move(ip));
            }
            return;
        }

        if (segStart == s.size())
        {
            return;
        }

        if (s[segStart] == '0')
        {
            // 不能有前导0,如果当前数为0，回溯
            segments[segId] = 0;
            dfs(s, segId + 1, segStart + 1);
        }

        // 枚举所有情况
        int addr = 0;
        for (int segEnd = segStart; segEnd < s.size(); segEnd++)
        {
            addr = addr * 10 + (s[segEnd] - '0');
            if (addr >= 0 && addr <= 255)
            {
                segments[segId] = addr;
                dfs(s, segId + 1, segEnd + 1);
            }
            else
            {
                break;
            }
        }
    }

public:
    vector<string> restoreIpAddresses(string s)
    {
        segments.resize(SEG_COUNT);
        dfs(s, 0, 0);
        return ret;
    }
};
// @lc code=end
