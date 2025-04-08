/*
 * @lc app=leetcode.cn id=3396 lang=csharp
 *
 * [3396] 使数组元素互不相同所需的最少操作次数
 */

// @lc code=start
public class Solution
{
    //用哈希表判断每个数字出现的次数
    public int MinimumOperations(int[] nums)
    {
        int ret = 0;
        for (int i = 0; i < nums.Length; i += 3)
        {
            if (Checked(nums, i))
            {
                return ret;
            }
            ret++;
        }
        return ret;
    }

    private bool Checked(int[] nums, int startIndex)
    {
        HashSet<int> set = new HashSet<int>();
        for (int i = startIndex; i < nums.Length; i++)
        {
            if (set.Contains(nums[i]))
            {
                return false;
            }
            set.Add(nums[i]);
        }
        return true;
    }
}

// @lc code=end
