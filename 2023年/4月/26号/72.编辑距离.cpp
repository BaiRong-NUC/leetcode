/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 */
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
Accepted
1146/1146 cases passed (20 ms)
Your runtime beats 26.61 % of cpp submissions
Your memory usage beats 78.56 % of cpp submissions (8.7 MB)
 */

// @lc code=start
class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int length_word1 = word1.length();
        int length_word2 = word2.length();

        if (length_word1 * length_word2 == 0)
        {
            // 有一个串为空串
            return length_word1 + length_word2;
        }
        // dp[i][j]:word1前i个字符变成word2前j个字符的最小步骤
        vector<vector<int>> dp(length_word1 + 1, vector<int>(length_word2 + 1, 0));
        // 边界初始化
        for (int i = 0; i <= length_word1; i++)
        {
            dp[i][0] = i;
        }
        for (int j = 0; j <= length_word2; j++)
        {
            dp[0][j] = j;
        }

        for (int i = 1; i <= length_word1; i++)
        {
            for (int j = 1; j <= length_word2; j++)
            {

                int part = dp[i - 1][j - 1];
                if (word1[i - 1] != word2[j - 1])
                {
                    part += 1;
                }
                dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]) + 1, part);
            }
        }

        return dp[length_word1][length_word2];
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution solution;
    solution.minDistance("horse", "ros");
    return 0;
}
