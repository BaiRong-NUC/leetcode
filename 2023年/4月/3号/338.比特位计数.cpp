/*
 * @lc app=leetcode.cn id=338 lang=cpp
 *
 * [338] 比特位计数
 */

#include <vector>
#include <string>
#include <map>
#include <iostream>

using namespace std;

// @lc code=start
class Solution
{
    // 二进制字符串加法
    string addStrings(string num1, string num2)
    {
        int carry = 0;
        string result = "";

        // 从右往左遍历两个字符串，将对应位的数字相加
        for (int i = num1.size() - 1, j = num2.size() - 1; i >= 0 || j >= 0 || carry == 1; i--, j--)
        {
            int a = i >= 0 ? num1[i] - '0' : 0;
            int b = j >= 0 ? num2[j] - '0' : 0;
            int sum = a + b + carry;
            carry = sum / 2;
            result = to_string(sum % 2) + result;
        }

        return result;
    }

    int coutOne(string &str)
    {
        map<char, int> char_counts;

        for (char c : str)
        {
            char_counts[c]++;
        }
        return char_counts['1'];
    }

public:
    vector<int> countBits(int n)
    {
        vector<int> vet;
        vet.push_back(0);
        string str = "0";
        for (int i = 0; i < n; i++)
        {
            str = addStrings(str, "1");
            cout << str << endl;
            vet.push_back(coutOne(str));
        }
        return vet;
    }
};
// @lc code=end
