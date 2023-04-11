/*
 * @lc app=leetcode.cn id=929 lang=cpp
 *
 * [929] 独特的电子邮件地址
 */

#include <vector>
#include <string>
#include <set>

using namespace std;

/**
 * Accepted
 * 186/186 cases passed (24 ms)
 * Your runtime beats 56.14 % of cpp submissions
 * Your memory usage beats 75.44 % of cpp submissions (13.5 MB)
 */

// @lc code=start
class Solution
{
public:
    int numUniqueEmails(vector<string> &emails)
    {
        set<string> emails_set;
        for (int i = 0; i < emails.size(); i++)
        {
            string email = "";
            for (auto &ch : emails[i])
            {
                if (ch == '+' || ch == '@')
                {
                    break;
                }
                else if (ch != '.')
                {
                    email += ch;
                }
            }
            emails_set.insert(email + emails[i].substr(emails[i].find('@')));
        }
        return emails_set.size();
    }
};
// @lc code=end
