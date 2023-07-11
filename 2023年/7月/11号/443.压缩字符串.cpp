/*
 * @lc app=leetcode.cn id=443 lang=cpp
 *
 * [443] 压缩字符串
 */

#include <vector>
#include <algorithm>
using namespace std;

/**
Accepted
75/75 cases passed (4 ms)
Your runtime beats 85.75 % of cpp submissions
Your memory usage beats 91.78 % of cpp submissions (8.7 MB)
 */
// @lc code=start
class Solution
{
public:
    int compress(vector<char> &chars)
    {
        int size = chars.size();
        int write = 0;
        int left = 0;
        for (int read = 0; read < size; read++)
        {
            if (read == size - 1 || chars[read] != chars[read + 1])
            {
                chars[write++] = chars[read];
                int num = read - left + 1;
                if (num > 1)
                {
                    int begin = write;
                    while (num > 0)
                    {
                        chars[write++] = num % 10 + '0';
                        num /= 10;
                    }
                    reverse(&chars[begin], &chars[write]);
                }
                left = read + 1;
            }
        }
        return write;
    }
};
// @lc code=end
