/*
 * @lc app=leetcode.cn id=2595 lang=csharp
 *
 * [2595] 奇偶位数
 */

// @lc code=start
public class Solution
{
    public int[] EvenOddBit(int n)
    {
        int even = 0, odd = 0;
        int index = 0;
        while (n > 0)
        {
            if ((n & 1) == 1)
            {
                if (index % 2 == 0) even++;
                else odd++;
            }
            index++;
            n >>= 1;
        }
        return new int[] { even, odd };
    }
}
// @lc code=end
