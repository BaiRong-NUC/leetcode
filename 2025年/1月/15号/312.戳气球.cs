/*
 * @lc app=leetcode.cn id=312 lang=csharp
 *
 * [312] 戳气球
 */

// @lc code=start
public class Solution
{
    //回溯所有可能情况超时
    /**
        Time Limit Exceeded
            21/73 cases passed (N/A)
        Testcase
            [7,9,8,0,7,1,3,5,5]
        Expected Answer
            1533
    */
    #region 
    int ret = int.MinValue;
    int GetPoint(int[] nums, int i)
    {
        int left = i - 1 >= 0 ? nums[i - 1] : 1;
        int right = i + 1 < nums.Length ? nums[i + 1] : 1;
        return left * nums[i] * right;
    }
    public void backtrack(int[] nums, int score)
    {
        //base case
        if (nums.Length == 0)
        {
            ret = Math.Max(ret, score);
            return;
        }
        //穷举所有可能选择
        for (int i = 0; i < nums.Length; i++)
        {
            int point = GetPoint(nums, i);
            //选择
            int choice = nums[i];
            //从数组中删除选择
            int[] newNums = nums.Where((val, idx) => idx != i).ToArray();
            //回溯
            backtrack(newNums, score + point);
            //撤销选择， 将选择重新插入到数组中
            nums = newNums.Take(i).Concat(new[] { choice }).Concat(newNums.Skip(i)).ToArray();
        }
    }
    #endregion

    //动态规划
    /**
        Accepted
            73/73 cases passed (54 ms)
            Your runtime beats 60 % of csharp submissions
            Your memory usage beats 6.67 % of csharp submissions (42.7 MB)
    */
    #region 
    public int MaxCoins(int[] nums)
    {
        // backtrack(nums, 0); //回溯所有戳破情况，取最大值超时
        // return ret;

        //动态规划
        //初始化point数组
        int[] point = new int[nums.Length + 2]; //加入两个虚拟球，分数是1
        point[0] = point[nums.Length + 1] = 1;
        for (int i = 1; i <= nums.Length; i++)
        {
            point[i] = nums[i - 1];
        }
        //dp[i][j]=x; 表示戳破气球i和气球j之间，不包括i和j的所有气球，可以获得的最高分数为x
        int[,] dp = new int[point.Length, point.Length];
        //设气球i到气球j之间最后破的是k，那么dp[i][j] = dp[i][k] + dp[k][j] + point[i]*point[k]*point[j]
        //dp从下向上遍历
        for (int i = point.Length - 1; i >= 0; i--)
        {
            for (int j = i + 1; j < point.Length; j++)
            {
                //穷举最后一个破的气球
                for (int k = i + 1; k < j; k++)
                {
                    dp[i, j] = Math.Max(dp[i, j], dp[i, k] + dp[k, j] + point[i] * point[k] * point[j]);
                }
            }
        }
        return dp[0, point.Length - 1];
    }
    #endregion
}
// @lc code=end