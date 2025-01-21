using System;
using System.Collections.Generic;

namespace LeetCode
{
    public class Solution
    {
        public int LengthOfLongestSubsequence(IList<int> nums, int target)
        {
            // dp[i][j]表示前i个物品，背包容量为j时的所有情况,最后结果为dp[nums.Count][target]
            int[,] dp = new int[nums.Count + 1, target + 1];
            // dp[0][0]=0;dp[0][j]=-1(不存在)
            for (int j = 1; j <= target; j++)
                dp[0, j] = -1;

            for (int i = 1; i <= nums.Count; i++)
            {
                for (int j = 0; j <= target; j++)
                {
                    // 第i个物品的重量为nums[i-1]大于j，一定不能选择
                    if (j - nums[i - 1] < 0)
                        dp[i, j] = dp[i - 1, j];
                    else
                        //可以选，可以不选
                        dp[i, j] = Math.Max(dp[i - 1, j], dp[i - 1, j - nums[i - 1]] + 1);
                }
            }
            return dp[nums.Count, target];
        }

    }
}