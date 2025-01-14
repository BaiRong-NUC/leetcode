/*
 * @lc app=leetcode.cn id=2680 lang=csharp
 *
 * [2680] 最大或值
 */

// @lc code=start
public class Solution
{
    //前后缀分离，记录后缀每个元素和剩余数组元素的或值
    public long MaximumOr(int[] nums, int k)
    {
        int[] suffix = new int[nums.Length + 1];
        for (int i = nums.Length - 1; i >= 0; i--)
        {
            suffix[i] = suffix[i + 1] | nums[i];
        }
        long res = 0;
        long pre = 0;//前缀或值
        //每个元素都进行枚举
        for (int i = 0; i < nums.Length; i++)
        {
            res = Math.Max(res, pre | (long)nums[i] << k | suffix[i + 1]);
            pre |= nums[i];//更新前缀或值
        }
        return res;
    }
}
// @lc code=end

