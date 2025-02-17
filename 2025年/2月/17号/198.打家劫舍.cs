/*
 * @lc app=leetcode.cn id=198 lang=csharp
 *
 * [198] 打家劫舍
 */

// @lc code=start
public class Solution
{
    public int Rob(int[] nums)
    {
        //dp[i]表示前i个房子可以偷到的最大金额
        int[] dp = new int[nums.Length + 1];
        dp[0] = 0;
        dp[1] = nums[0];
        for (int i = 2; i <= nums.Length; i++)
        {
            //第i个房子的金额为nums[i-1]
            //选择偷或者不偷
            dp[i] = Math.Max(dp[i - 1], dp[i - 2] + nums[i - 1]);
        }
        return dp[nums.Length];
    }
}
// @lc code=end

