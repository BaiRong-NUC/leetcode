/*
 * @lc app=leetcode.cn id=887 lang=csharp
 *
 * [887] 鸡蛋掉落
 */

// @lc code=start
public class Solution
{
    //折半查找优化线性搜索

    //记录结果，防止重复遍历
    Dictionary<string, int> memo = new Dictionary<string, int>();
    //dp[k,n]表示k个鸡蛋，n层楼，最坏情况下最少需要扔多少次鸡蛋
    public int dp(int k, int n)
    {
        //递归出口
        if (n == 0) { return 0; }
        if (k == 1) { return n; }
        //正常情况
        string key = k.ToString() + n.ToString();
        if (memo.ContainsKey(key))
        {
            return memo[key];
        }
        else
        {
            int ret = int.MaxValue;
            int left = 1; int right = n; //[left,right]

            //min(ret,max(dp(k,n-i),dp(k-1,i-1)))
            while (left <= right)
            {
                int mid = left + (right - left) / 2;
                int broken = dp(k - 1, mid - 1); //关于mid递增
                int notBroken = dp(k, n - mid);  //关于mid递减
                if (broken > notBroken)
                {
                    right = mid - 1;
                    ret = Math.Min(ret, broken + 1);
                }
                else if (broken < notBroken)
                {
                    left = mid + 1;
                    ret = Math.Min(ret, notBroken + 1);
                }
                else
                {
                    //找到交点
                    ret = Math.Min(ret, broken + 1);
                    break;
                }
            }
            memo[key] = ret;
            return ret;
        }
    }
    public int SuperEggDrop(int k, int n)
    {
        return dp(k, n);
    }
}
// @lc code=end

