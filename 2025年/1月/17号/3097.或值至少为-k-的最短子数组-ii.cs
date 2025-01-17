/*
 * @lc app=leetcode.cn id=3097 lang=csharp
 *
 * [3097] 或值至少为 K 的最短子数组 II
 */

// @lc code=start
public class Solution
{
    int[] bits = new int[32];
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
        return ret;
    }
    public int MinimumSubarrayLength(int[] nums, int k)
    {
        //滑动窗口
        int left = 0, right = 0;
        int sum = 0;
        int ans = int.MaxValue;
        while (right < nums.Length)
        {
            for (int i = 0; i < 32; i++)
            {
                bits[i] += (nums[right] >> i) & 1;
            }
            //收缩左区间
            while (left <= right && or(bits) >= k)
            {
                ans = Math.Min(ans, right - left + 1);
                //将数字移除窗口
                for (int i = 0; i < 32; i++)
                {
                    bits[i] -= (nums[left] >> i) & 1;
                }
                left += 1;
            }
            right += 1;
        }
        return ans == int.MaxValue ? -1 : ans;
    }
}
// @lc code=end

