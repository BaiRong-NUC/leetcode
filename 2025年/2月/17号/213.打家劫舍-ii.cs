/*
 * @lc app=leetcode.cn id=213 lang=csharp
 *
 * [213] 打家劫舍 II
 */

// @lc code=start
public class Solution
{
    public int Rob(int[] nums)
    {
        if (nums.Length == 0) return 0;
        //只有一个房子，只有一个选择
        if (nums.Length == 1) return nums[0];
        //dp[i]表示前i个房子可以偷到的最大金额
        int[] dp = new int[nums.Length + 1];
        //相比198题，多了一个条件，就是第一个房子和最后一个房子不能同时偷
        //所以可以分为三种情况
        //1. 偷第一个房子，不偷最后一个房子。所以dp[nums.Length]不能用
        //2. 不偷第一个房子，偷最后一个房子，所以dp[nums.Length]可以用
        //3. 第一个和最后一个房子都不偷，这种情况上述1，2已经包括了

        // 偷第一个房子，不偷最后一个房子
        dp[0] = 0;
        dp[1] = nums[0];
        //不包括最后一个房子
        for (int i = 2; i < nums.Length; i++)
        {
            dp[i] = Math.Max(dp[i - 1], dp[i - 2] + nums[i - 1]);
        }
        int robFirst = dp[nums.Length - 1];

        // 不偷第一个房子，偷最后一个房子
        dp[0] = 0;
        dp[1] = 0;
        //包括最后一个房子
        for (int i = 2; i <= nums.Length; i++)
        {
            dp[i] = Math.Max(dp[i - 1], dp[i - 2] + nums[i - 1]);
        }
        int notRobFirst = dp[nums.Length];

        return Math.Max(robFirst, notRobFirst);
    }
}
// @lc code=end

