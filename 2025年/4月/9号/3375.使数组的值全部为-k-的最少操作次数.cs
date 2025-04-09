/*
 * @lc app=leetcode.cn id=3375 lang=csharp
 *
 * [3375] 使数组的值全部为 K 的最少操作次数
 */

// @lc code=start
public class Solution
{
    public int MinOperations(int[] nums, int k)
    {
        //数组中比k大的元素种类即为答案，若数组中存在比k小的数字则没有答案
        HashSet<int> hashSet = new HashSet<int>();
        foreach (int num in nums)
        {
            if (num < k)
            {
                return -1;
            }
            else if (num > k)
            {
                hashSet.Add(num);
            }
        }
        return hashSet.Count();
    }
}
// @lc code=end
