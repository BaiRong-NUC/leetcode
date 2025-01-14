/*
 * @lc app=leetcode.cn id=1312 lang=csharp
 *
 * [1312] 让字符串成为回文串的最少插入次数
 */

// @lc code=start
public class Solution
{
    public int MinInsertions(string s)
    {
        // dp[i][j] 表示 s[i..j] 成为回文串的最少插入次数
        List<List<int>> dp = new List<List<int>>(s.Length);
        for (int i = 0; i < s.Length; i++)
        {
            //构成二维数组
            dp.Add(new List<int>(s.Length));
            for (int j = 0; j < s.Length; j++)
            {
                dp[i].Add(0);//全部初始化为0
            }
        }
        for (int i = s.Length - 1; i >= 0; i--)
        {
            for (int j = i + 1; j < s.Length; j++)
            {
                if (s[i] == s[j])
                {
                    dp[i][j] = dp[i + 1][j - 1];
                }
                else
                {
                    dp[i][j] = Math.Min(dp[i + 1][j], dp[i][j - 1]) + 1;
                }
            }
        }
        return dp[0][s.Length - 1];
    }
}
// @lc code=end

