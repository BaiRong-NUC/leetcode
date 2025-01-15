/*
 * @lc app=leetcode.cn id=10 lang=csharp
 *
 * [10] 正则表达式匹配
 */

// @lc code=start
public class Solution
{
    public bool IsMatch(string s, string p)
    {
        //dp[i,j]表示s的前i个字符与p的前j个字符是否匹配,默认值全部为false
        bool[,] dp = new bool[s.Length + 1, p.Length + 1];
        //初始化dp
        dp[0, 0] = true;
        for (int j = 2; j < p.Length + 1; j++)
        {
            //s串为空，p串必须是字母+*的形式
            dp[0, j] = (p[j - 1] == '*') && (dp[0, j - 2]);
        }
        for (int i = 1; i < s.Length + 1; i++)
        {
            for (int j = 1; j < p.Length + 1; j++)
            {
                if (p[j - 1] == '*')
                {
                    //*前的字母匹配零次
                    if (dp[i, j - 2]) { dp[i, j] = true; }
                    //*前的字母匹配多次
                    else if (dp[i - 1, j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.')) { dp[i, j] = true; }
                }
                else
                {
                    //匹配一次
                    if (dp[i - 1, j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.')) { dp[i, j] = true; }
                }
            }
        }
        return dp[s.Length, p.Length];
    }
}
// @lc code=end

