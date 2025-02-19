/*
 * @lc app=leetcode.cn id=624 lang=csharp
 *
 * [624] 数组列表中的最大距离
 */

// @lc code=start
public class Solution
{
    public int MaxDistance(IList<IList<int>> arrays)
    {
        int maxDist = 0;
        // /2防止越界
        int minValue = int.MaxValue / 2;//记录当前遍历过数组的最小值
        int maxValue = int.MinValue / 2;//记录当前遍历过数组的最大值
        foreach (var array in arrays)
        {
            //first是当前数组的最小值，last是当前数组的最大值
            int first = array[0], last = array[array.Count - 1];
            maxDist = Math.Max(maxDist, Math.Max(last - minValue, maxValue - first));
            minValue = Math.Min(minValue, first);
            maxValue = Math.Max(maxValue, last);
        }
        return maxDist;
    }
}
// @lc code=end

