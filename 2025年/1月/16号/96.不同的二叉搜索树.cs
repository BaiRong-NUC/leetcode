/*
 * @lc app=leetcode.cn id=96 lang=csharp
 *
 * [96] 不同的二叉搜索树
 */

// @lc code=start
public class Solution
{
    public int NumTrees(int n)
    {
        //dp[i]表示i个结点的不同二叉搜索树的个数
        int[] dp = new int[n + 1];
        dp[0] = dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            //节点个数从2开始遍历
            for (int j = 1; j <= i; j++)
            {
                //j-1为根节点左子树的节点个数，i-j为根节点右子树的节点个数，j为根
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }
        return dp[n];
    }
}
// @lc code=end

