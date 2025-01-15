/*
 * @lc app=leetcode.cn id=887 lang=csharp
 *
 * [887] 鸡蛋掉落
 */

// @lc code=start
public class Solution
{
    //字典记录已经计算过的结果
    Dictionary<string, int> memo = new Dictionary<string, int>();

    //dp[k,n]表示k个鸡蛋，n层楼，最坏情况下最少需要扔多少次鸡蛋
    public int dp(int k, int n)
    {
        //base case
        if (n == 0) { return 0; }  //楼层为0不需要扔鸡蛋
        if (k == 1) { return n; } //只有一个鸡蛋，只能线性扫描，一共需要扔n次
        string key = k.ToString() + "_" + n.ToString();
        if (memo.ContainsKey(key))
        {
            return memo[key];
        }
        else
        {
            int res = int.MaxValue;
            //穷举所有可能的选择
            for (int i = 1; i < n + 1; i++)
            {
                //dp(k,n-i)表示鸡蛋在第i层楼没碎，需要向上面的n-i层楼找，相当于第i层变为第0层剩下n-i层楼
                //dp(k-1,i-1)表示鸡蛋在第i层楼碎了需要向下面的i-1层楼找
                res = Math.Min(res, Math.Max(dp(k, n - i), dp(k - 1, i - 1)) + 1);
            }
            //记录结果
            memo[key] = res;
            return res;
        }

    }
    //如果不限制鸡蛋个数，二分法即可
    public int SuperEggDrop(int k, int n)
    {
        return dp(k, n);
    }
}
// @lc code=end

