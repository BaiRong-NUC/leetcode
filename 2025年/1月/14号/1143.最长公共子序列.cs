/*
 * @lc app=leetcode.cn id=1143 lang=csharp
 *
 * [1143] 最长公共子序列
 */

// @lc code=start
public class Solution
{
    public int LongestCommonSubsequence(string text1, string text2)
    {
        // dp[i][j] 表示text1[0..i]和text2[0..j]的最长公共子序列
        int[,] dp = new int[text1.Length + 1, text2.Length + 1];
        // Console.WriteLine("text1.Length:" + text1.Length + " text2.Length:" + text2.Length);
        for (int i = 1; i <= text1.Length; i++)
        {
            for (int j = 1; j <= text2.Length; j++)
            {
                if (text1[i - 1] == text2[j - 1])
                {
                    dp[i, j] = dp[i - 1, j - 1] + 1;
                }
                else
                {
                    dp[i, j] = Math.Max(dp[i, j - 1], dp[i - 1, j]);
                }
            }
        }
        return dp[text1.Length, text2.Length];
    }
}
// @lc code=end

Solution s = new Solution();
s.LongestCommonSubsequence("abcde", "ace");