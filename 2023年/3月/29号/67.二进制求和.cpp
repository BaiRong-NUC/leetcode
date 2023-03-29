/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 */

#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

// @lc code=start
class Solution
{
public:
    string addBinary(string a, string b)
    {
        int flag = 0; // 进位
        int a_del = a.length() - 1;
        int b_del = b.length() - 1;
        string ret = "";
        while (a_del >= 0 && b_del >= 0)
        {
            int num_a = a[a_del] - '0';
            int num_b = b[b_del] - '0';
            int num_ret = (num_b ^ num_a) + flag;
            flag = 0;
            if (num_ret == 2)
            {
                num_ret = 0;
                flag = 1;
            }
            else if (a[a_del] == '1' && b[b_del] == '1')
            {
                flag = 1;
            }
            ret.push_back('0' + num_ret);
            a_del--;
            b_del--;
        }
        while (a_del >= 0)
        {
            char insert = a[a_del] + flag;
            flag = 0;
            if (insert == '2')
            {
                flag = 1;
                insert = '0';
            }
            ret.push_back(insert);
            a_del--;
        }
        while (b_del >= 0)
        {
            char insert = b[b_del] + flag;
            flag = 0;
            if (insert == '2')
            {
                flag = 1;
                insert = '0';
            }
            ret.push_back(insert);
            b_del--;
        }
        if (flag != 0)
        {
            ret.push_back('1');
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    string a = "1111";
    string b = "1111";
    Solution solution;
    cout << solution.addBinary(a, b);
    return 0;
}
