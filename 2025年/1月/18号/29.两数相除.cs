/*
 * @lc app=leetcode.cn id=29 lang=csharp
 *
 * [29] 两数相除
 */

// @lc code=start
public class Solution
{
    public int Divide(int dividend, int divisor)
    {
        //判断除法结果的正负号,判断符号位是否相同
        int sign = ((((dividend ^ divisor) >> 31) & 0x1) == 1) ? -1 : 1;
        long res = 0;
        long dividendL = Math.Abs((long)dividend); //转换为正的长整型。防止计算时溢出
        long divisorL = Math.Abs((long)divisor); //转换为正的长整型。防止计算时溢出
        //利用减法实现除法，并且减数每次翻倍提高效率
        while (dividendL >= divisorL)
        {
            long quotient = 1; //商
            long divisorLSub = divisorL;
            while (dividendL >= divisorLSub)
            {
                dividendL -= divisorLSub;
                res += quotient;
                quotient <<= 1;
                divisorLSub <<= 1;
            }
            //可能会出现dividendL < divisorL的情况，商太大了
            //此时需要将divisorLSub和quotient还原
        }
        res = sign * res;
        //判断是否溢出
        if (res > int.MaxValue) return int.MaxValue;
        else if (res < int.MinValue) return int.MinValue;
        else return (int)res;
    }
}
// @lc code=end

