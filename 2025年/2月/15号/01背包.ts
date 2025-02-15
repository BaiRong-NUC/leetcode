class Solution {
    // 01背包问题, 有n个物品，每个物品有重量和价值，背包容量为w，求背包能装的最大价值
    knapsack(w: number, n: number, wt: number[], val: number[]): number {
        // dp[i][j]表示前i个物品，容量为j的背包能装的最大价值，所求答案为dp[n][w]
        // dp[i][0]=0,dp[0][j]=0
        const dp: number[][] = new Array(n + 1).fill(0).map(() => new Array(w + 1).fill(0));
        for (let i = 1; i <= n; i++) {
            for (let j = 1; j <= w; j++) {
                if (j - wt[i - 1] < 0) {
                    // 容量不足，不能装第i个物品
                    dp[i][j] = dp[i - 1][j];
                } else {
                    // 容量充足，可以选择装第i个物品
                    dp[i][j] = Math.max(dp[i - 1][j], dp[i - 1][j - wt[i - 1]] + val[i - 1]);
                }
            }
        }
        return dp[n][w];
    }
}