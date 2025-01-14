/*
 * @lc app=leetcode.cn id=3065 lang=csharp
 *
 * [3065] 超过阈值的最少操作数 I
 */

// @lc code=start
public class Solution {
    public int MinOperations(int[] nums, int k) {
        int res = 0;
        foreach (int num in nums) {
            if (num < k) {
                res++;
            }
        }
        return res;
    }
}
// @lc code=end

