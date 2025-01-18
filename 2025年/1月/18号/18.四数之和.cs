/*
 * @lc app=leetcode.cn id=18 lang=csharp
 *
 * [18] 四数之和
 */

// @lc code=start
public class Solution
{
    public IList<IList<int>> FourSum(int[] nums, int target)
    {
        List<List<int>> res = new List<List<int>>();
        if (nums.Length < 4) return res.ToArray();

        //先对nums排序
        Array.Sort(nums);
        for (int i = 0; i < nums.Length - 3; i++)
        {
            //剪枝
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            //最小四个数之和大于target，后面不可能再找到
            if ((long)nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) break;

            //最大四个数之和小于target，后面不可能再找到
            if ((long)nums[i] + nums[nums.Length - 3] + nums[nums.Length - 2] + nums[nums.Length - 1] < target) continue;

            for (int j = i + 1; j < nums.Length - 2; j++)
            {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                if ((long)nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) break;

                if ((long)nums[i] + nums[j] + nums[nums.Length - 2] + nums[nums.Length - 1] < target) continue;

                int left = j + 1;
                int right = nums.Length - 1;
                //双指针找两数之和
                while (left < right)
                {
                    long sum = nums[i] + nums[j] + nums[left] + nums[right];
                    if (sum == target)
                    {
                        res.Add(new List<int> { nums[i], nums[j], nums[left], nums[right] });
                        //去掉重复值
                        while (left < right && nums[left] == nums[left + 1]) left++;
                        left++; //重新指向新位置
                        while (left < right && nums[right] == nums[right - 1]) right--;
                        right--; //重新指向新位置
                    }
                    else if (sum < target)
                    {
                        left++;
                    }
                    else
                    {
                        //(sum > target)
                        right--;
                    }
                }
            }
        }
        return res.ToArray();
    }
}
// @lc code=end

