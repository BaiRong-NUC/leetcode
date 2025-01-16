/*
 * @lc app=leetcode.cn id=3095 lang=csharp
 *
 * [3095] 或值至少 K 的最短子数组 I
 */

// @lc code=start
public class Solution
{
    #region 
    // public int MinimumSubarrayLength(int[] nums, int k)
    // {
    //     //暴力枚举
    //     int ret = int.MaxValue;
    //     for (int i = 0; i < nums.Length; i++)
    //     {
    //         int or = 0;
    //         for (int j = i; j < nums.Length; j++)
    //         {
    //             or |= nums[j];
    //             if (or >= k)
    //             {
    //                 ret = Math.Min(ret, j - i + 1);
    //                 break;
    //             }
    //         }
    //     }
    //     return ret == int.MaxValue ? -1 : ret;
    // }
    #endregion
    //判断bits数组中是否有元素大于等于k
    public int or(int[] bits)
    {
        int ret = 0;
        for (int i = 0; i < 32; i++)
        {
            if (bits[i] > 0)
            {
                ret |= (1 << i);
            }
        }
        // Console.WriteLine("or:" + ret);
        return ret;
    }
    public int MinimumSubarrayLength(int[] nums, int k)
    {
        //滑动窗口
        int left = 0; int right = 0;
        int ret = int.MaxValue;
        //记录窗口元素每位上的1的个数
        int[] bits = new int[32];
        while (right < nums.Length)
        {
            for (int i = 0; i < 32; i++)
            {
                //如果第i位为1，那么bits[i]++
                bits[i] += (nums[right] >> i) & 1;
            }
            //收缩左区间
            while (left <= right && or(bits) >= k)
            {
                ret = Math.Min(ret, right - left + 1);
                // Console.WriteLine("left:" + left + " right:" + right);
                for (int i = 0; i < 32; i++)
                {
                    //如果第i位为1，那么bits[i]--
                    bits[i] -= (nums[left] >> i) & 1;
                }
                left++;
            }
            right++;
        }
        return ret == int.MaxValue ? -1 : ret;
    }
}
// @lc code=end

Solution solution = new Solution();
solution.MinimumSubarrayLength(new int[] { 1, 2, 3 }, 2);