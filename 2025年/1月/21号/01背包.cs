public class Solution
{
    // 01背包问题, 有n个物品，每个物品有重量和价值，背包容量为w，求背包能装的最大价值
    public int knapsack(int w, int n, int[] wt, int[] val)
    {
        // dp[i][j]表示前i个物品，背包容量为j时的最大价值,dp[0][j] = 0, dp[i][0] = 0
        int[,] dp = new int[n + 1, w + 1];
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= w; j++)
            {
                // 第i个物品的重量为wt[i-1],价值为val[i-1]
                if (j - wt[i - 1] < 0)//这个物品放不下了
                    dp[i, j] = dp[i - 1, j];
                else//这个物品放的下，选择放或者不放
                    dp[i, j] = max(dp[i - 1, j], dp[i - 1, j - wt[i - 1]] + val[i - 1])
            }
        }
        return dp[n, w];
    }
}