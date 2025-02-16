/*
 * @lc app=leetcode.cn id=518 lang=csharp
 *
 * [518] 零钱兑换 II
 */

// @lc code=start
public class Solution
{
    //背包问题第三种变式，完全背包问题
    public int Change(int amount, int[] coins)
    {
        //dp[i][j]表示前i个硬币，装入重量为j的背包的所有可能情况
        int[,] dp = new int[coins.Length + 1, amount + 1];
        dp[0, 0] = 1;//背包容量为0时，只有一种方案，就是不放任何硬币
        for (int i = 1; i <= coins.Length; i++)
        {
            for (int j = 0; j <= amount; j++)
            {
                //第i个硬币的重量为coins[i-1]
                if (j - coins[i - 1] < 0)
                {
                    dp[i, j] = dp[i - 1, j];
                }
                else
                {
                    //这个硬币放的下，选择放或者不放,所有可能情况是二者的和
                    dp[i, j] = dp[i - 1, j] + dp[i, j - coins[i - 1]];
                }
            }
        }
        return dp[coins.Length, amount];
    }
}
// @lc code=end

