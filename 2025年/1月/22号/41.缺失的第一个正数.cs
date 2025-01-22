/*
 * @lc app=leetcode.cn id=41 lang=csharp
 *
 * [41] 缺失的第一个正数
 */

// @lc code=start
public class Solution
{
    public int FirstMissingPositive(int[] nums)
    {
        //原地哈希
        //1. 遍历数组，将负数和0替换为n+1
        //2. 遍历数组，将数组中小于等于n的数对应的下标位置的数变为负数
        //3. 遍历数组，找到第一个正数的下标，返回下标+1
        int n = nums.Length;
        Action<int[], int, int> swap = (arr, i, j) =>
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        };
        for (int i = 0; i < n; i++)
        {
            if (nums[i] <= 0) nums[i] = n + 1;
            //元素为正num，放到应该放的位置上nums[num-1]
            //while 当交换后元素为正，需要在进行一次交换判断。如果和正确位置已经有了相同的元素，则不需要交换，否则会陷入死循环
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i])
            {
                swap(nums, i, nums[i] - 1);
            }
        }
        for (int j = 0; j < n; j++)
        {
            if (nums[j] != j + 1) return j + 1;
        }
        return n + 1;
    }
}
// @lc code=end

