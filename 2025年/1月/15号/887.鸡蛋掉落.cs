/*
 * @lc app=leetcode.cn id=887 lang=csharp
 *
 * [887] 鸡蛋掉落
 */

// @lc code=start
public class Solution
{
    //递归+记忆动态规划超时
    #region 
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
    #endregion

    //二分法优化线性搜索
    #region 
    //利用二分法代替线性搜索
    public int _DpHalfSearch(int k, int n)
    {
        if (n == 0) { return 0; }
        if (k == 1) { return n; }
        string key = k.ToString() + n.ToString();
        if (memo.ContainsKey(key))
        {
            return memo[key];
        }
        else
        {
            //交点处就能保证这两个函数的最大值最小
            int res = int.MaxValue;
            int left = 1; int right = n; //[left,right]
            while (left <= right)
            {
                int mid = left + (right - left) / 2; //防止溢出
                int broken = _DpHalfSearch(k - 1, mid - 1); //碎了
                int notBroken = _DpHalfSearch(k, n - mid); //没碎
                if (broken > notBroken)//两函数交点在mid左边
                {
                    right = mid - 1;
                    res = Math.Min(res, broken + 1);
                }
                else if (broken < notBroken)//两函数交点在mid右边
                {
                    left = mid + 1;
                    res = Math.Min(res, notBroken + 1);
                }
                else
                {
                    //找到对应位置
                    left = right = mid;
                    res = Math.Min(res, broken + 1);
                    break;
                }
            }
            memo[key] = res;
            return res;
        }
    }
    #endregion

    //如果不限制鸡蛋个数，二分法即可
    public int SuperEggDrop(int k, int n)
    {
        // return dp(k, n);//递归+记忆动态规划超时
        // return _DpHalfSearch(k, n); //二分法优化线性搜索
        //修改dp数组的定义
        //dp[k,n]表示k个鸡蛋，最多允许扔n次，最多能够确定的楼层数
        int[,] dp = new int[k + 1, n + 1]; //初始化为0
        int ret = 0;
        while (dp[k, ret] < n)
        {
            ret += 1;
            //穷举所有可能的鸡蛋个数
            for (int i = 1; i <= k; i++)
            {
                //dp[i,ret-1]表示鸡蛋没碎，可以确定的楼层数
                //dp[i-1,ret-1]表示鸡蛋碎了，可以确定的楼层数
                dp[i, ret] = dp[i, ret - 1] + dp[i - 1, ret - 1] + 1;
            }
        }
        return ret;
    }
}
// @lc code=end

