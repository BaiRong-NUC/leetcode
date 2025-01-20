/*
 * @lc app=leetcode.cn id=2239 lang=csharp
 *
 * [2239] 找到最接近 0 的数字
 */

// @lc code=start
public class Solution
{
    public int FindClosestNumber(int[] nums)
    {
        int ret = 0;
        int min = int.MaxValue;
        foreach (var v in nums)
        {
            if (Math.Abs(v) < min)
            {
                ret = v;
            }
            else if (Math.Abs(v) == min)
            {
                ret = Math.Max(ret, v);
            }
            min = Math.Min(min, Math.Abs(v));
        }
        return ret;
    }
}
// @lc code=end

