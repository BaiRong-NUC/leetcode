/*
 * @lc app=leetcode.cn id=312 lang=csharp
 *
 * [312] 戳气球
 */

// @lc code=start
public class Solution
{
    public int MaxCoins(int[] nums)
    {
        int[] point = new int[nums.Length + 2];
        point[0] = point[point.Length - 1] = 1;
        //初始化point数组
        for (int i = 1; i < point.Length - 1; i++)
        {
            point[i] = nums[i - 1];
        }
        //dp[i,j]表示戳破(i,j)之间的气球，获得的最大金币
        int[,] dp = new int[point.Length, point.Length];
        //从下向上遍历
        for (int i = point.Length - 1; i >= 0; i--)
        {
            for (int j = i + 1; j < point.Length; j++)
            {
                //穷举所有可能打破的球
                for (int k = i + 1; k < j; k++)
                {
                    dp[i, j] = Math.Max(dp[i, j], dp[i, k] + point[i] * point[k] * point[j] + dp[k, j]);
                }
            }
        }
        return dp[0, point.Length - 1];
    }
}
// @lc code=end

