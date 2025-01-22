/*
 * @lc app=leetcode.cn id=1561 lang=csharp
 *
 * [1561] 你可以获得的最大硬币数目
 */

// @lc code=start
public class Solution
{
    public int MaxCoins(int[] piles)
    {
        //每次Alice取最大，Bob取最小，Me取次大
        //排序
        Array.Sort(piles);
        //轮次
        int round = piles.Length / 3;
        int ret = 0;
        int index = piles.Length - 2;
        for (int i = 0; i < round; i++)
        {
            ret += piles[index];
            index -= 2;
        }
        return ret;
    }
}
// @lc code=end

