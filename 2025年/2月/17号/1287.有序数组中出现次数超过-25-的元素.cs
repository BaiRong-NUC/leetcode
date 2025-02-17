/*
 * @lc app=leetcode.cn id=1287 lang=csharp
 *
 * [1287] 有序数组中出现次数超过25%的元素
 */

// @lc code=start
public class Solution
{
    public int FindSpecialInteger(int[] arr)
    {
        int length = arr.Length;
        int span = length / 4;
        int slow = 0; int fast = slow + span;
        while (fast < length)
        {
            if (arr[slow] == arr[fast]) return arr[slow];
            slow++;
            fast++;
        }
        return -1;
    }
}
// @lc code=end

