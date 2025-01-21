/*
 * @lc app=leetcode.cn id=416 lang=csharp
 *
 * [416] 分割等和子集
 */

// @lc code=start
public class Solution
{
    public bool CanPartition(int[] nums)
    {
        //将nums分成两个数组，两个数组的和相等。单个数组和为sum/2
        //等价为从nums中选择元素和为sum/2

        //dp[i][j]表示前i个元素，和为j时的所有情况
        //最后结果为dp[nums.Length][sum/2]
        int sum = nums.Sum();
        if (sum % 2 != 0) return false;

        bool[,] dp = new bool[nums.Length, sum / 2 + 1];

        //第一行
        if (nums[0] <= sum / 2) dp[0, nums[0]] = true;

        for (int i = 1; i < nums.Length; i++)
        {
            for (int j = 0; j <= sum / 2; j++)
            {
                if (j < nums[i])
                {
                    dp[i, j] = dp[i - 1, j];
                }
                else
                {
                    dp[i, j] = dp[i - 1, j] || dp[i - 1, j - nums[i]];
                }
            }
        }
        return dp[nums.Length - 1, sum / 2];
    }
}
// @lc code=end

