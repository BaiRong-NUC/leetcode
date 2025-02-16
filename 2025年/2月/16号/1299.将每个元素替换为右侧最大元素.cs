/*
 * @lc app=leetcode.cn id=1299 lang=csharp
 *
 * [1299] 将每个元素替换为右侧最大元素
 */

// @lc code=start
public class Solution
{
    public int[] ReplaceElements(int[] arr)
    {
        int length = arr.Length;
        int[] res = new int[length];
        res[length - 1] = -1;
        for (int i = length - 2; i >= 0; i--)
        {
            res[i] = Math.Max(res[i + 1], arr[i + 1]);
        }
        return res;
    }
}
// @lc code=end

