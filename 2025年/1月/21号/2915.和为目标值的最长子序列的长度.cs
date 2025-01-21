/*
 * @lc app=leetcode.cn id=2915 lang=csharp
 *
 * [2915] 和为目标值的最长子序列的长度
 */

// public class Solution
// {
//     public int LengthOfLongestSubsequence(IList<int> nums, int target)
//     {
//         int n = nums.Count;
//         int[][] dp = new int[n + 1][];
//         for (int i = 0; i <= n; i++)
//         {
//             dp[i] = new int[target + 1];
//         }
//         Array.Fill(dp[0], -1);
//         dp[0][0] = 0;
//         for (int i = 1; i <= n; i++)
//         {
//             Array.Copy(dp[i - 1], 0, dp[i], 0, target + 1);
//             int num = nums[i - 1];
//             for (int j = num; j <= target; j++)
//             {
//                 if (dp[i - 1][j - num] < 0)
//                 {
//                     continue;
//                 }
//                 dp[i][j] = Math.Max(dp[i][j], dp[i - 1][j - num] + 1);
//             }
//         }
//         return dp[n][target];
//     }
// }

// @lc code=start
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
                // 第i个物品的重量为nums[i-1]大于j，一定不能选择。此外，dp[i-1,j-nums[i-1]]<0表示没有办法使用i-1个物品凑出j-nums[i-1]，所以也不能选择
                if (j - nums[i - 1] < 0 || dp[i - 1, j - nums[i - 1]] < 0)
                    dp[i, j] = dp[i - 1, j];
                else
                    //可以选，可以不选
                    dp[i, j] = Math.Max(dp[i - 1, j], dp[i - 1, j - nums[i - 1]] + 1);
            }
        }
        return dp[nums.Count, target];
    }

}
// @lc code=end