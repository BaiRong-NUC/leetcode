/*
 * @lc app=leetcode.cn id=682 lang=cpp
 *
 * [682] 棒球比赛
 */

#include <vector>
#include <string>
#include <stack>

using namespace std;

// @lc code=start
class Solution
{
public:
    int calPoints(vector<string> &operations)
    {
        stack<int> grades;
        for (int i = 0; i < operations.size(); i++)
        {
            if (operations[i] == "+")
            {
                int first = grades.top();
                grades.pop();
                int second = grades.top();
                grades.push(first);
                grades.push(first + second);
            }
            else if (operations[i] == "C")
            {
                grades.pop();
            }
            else if (operations[i] == "D")
            {
                grades.push(grades.top() * 2);
            }
            else
            {
                grades.push(atoi(operations[i].c_str()));
            }
        }
        int ret = 0;
        while (!grades.empty())
        {
            ret += grades.top();
            grades.pop();
        }
        return ret;
    }
};
// @lc code=end
