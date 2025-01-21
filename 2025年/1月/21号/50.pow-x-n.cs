/*
 * @lc app=leetcode.cn id=50 lang=csharp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
public class Solution
{
    //超时
    // public double MyPow(double x, int n)
    // {
    //     if (x == 1 || n == 0) { return 1; }
    //     long N = n;
    //     x = (n > 0) ? x : 1 / x;
    //     double ret = 1;
    //     for (int i = 0; i < Math.Abs(N); i++)
    //     {
    //         ret *= x;
    //     }
    //     return ret;
    // }
    //快速幂（折半）
    public double Pow(double x, long n)
    {
        if (n == 0) { return 1; }
        double ret = Pow(x, n / 2);
        //偶数正好一般，奇数需要多乘一个x
        return n % 2 == 0 ? ret * ret : ret * ret * x;
    }
    public double MyPow(double x, int n)
    {
        if (x == 1 || n == 0) { return 1; }
        long N = n;
        return (N > 0) ? Pow(x, N) : 1 / Pow(x, -N);
    }
}
// @lc code=end