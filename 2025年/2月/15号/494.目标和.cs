/*
 * @lc app=leetcode.cn id=494 lang=csharp
 *
 * [494] 目标和
 */

// @lc code=start
public class Solution
{
    // 记数组的元素和为sum，添加-号的元素之和为neg，则其余添加+的元素之和为sum−neg，得到的表达式的结果为
    // (sum−neg)−neg=sum−2⋅neg=target
    // 即neg=(sum−target)/2
    // 相当于01背包问题，背包容量为neg，物品为数组中的元素，物品的价值为1，物品的重量为数组中的元素值
    // dp[i][j]表示前i个物品，背包容量为j时的所有可能情况,dp[0][j] = 0, dp[i][0] = 0
    public int FindTargetSumWays(int[] nums, int target)
    {
        int neg = (int)((nums.Sum() - target) / 2.0);
        //如果neg为负数或者(sum−target)不是偶数，则不存在答案
        if (neg < 0 || (nums.Sum() - target) % 2 != 0) return 0;
        //dp[i][j]表示前i个物品，背包容量为j时的所有可能情况,dp[0][j] = 1, dp[i][0] = 1(只有一种情况，不放任何东西)
        int[,] dp = new int[nums.Length + 1, neg + 1];
        dp[0, 0] = 1;//背包容量为0时，只有一种方案，就是不放任何物品
        for (int i = 1; i <= nums.Length; i++)
        {
            for (int j = 0; j <= neg; j++)
            {
                //第i个物品的重量为nums[i-1]
                if (j - nums[i - 1] < 0)
                {
                    //放不下这个物品
                    dp[i, j] = dp[i - 1, j];
                }
                else
                {
                    //这个物品放的下，选择放或者不放,所有可能情况是二者的和
                    dp[i, j] = dp[i - 1, j] + dp[i - 1, j - nums[i - 1]];
                }
            }
        }
        return dp[nums.Length, neg];
    }
}
// @lc code=end

