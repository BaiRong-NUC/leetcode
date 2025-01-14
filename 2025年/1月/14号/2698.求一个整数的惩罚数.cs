/*
 * @lc app=leetcode.cn id=2698 lang=csharp
 *
 * [2698] 求一个整数的惩罚数
 */

// @lc code=start
public class Solution
{
    bool Check(string s, int start, int sum, int target)
    {
        if (start == s.Length)
        {
            // Console.WriteLine("ans:" + ans + " sum:" + sum);
            return sum == target;
        }
        int ans = 0;
        for (int i = start; i < s.Length; i++)
        {
            ans = ans * 10 + int.Parse(s[i].ToString());
            //当前值已经大于目标值，直接返回false
            if (ans > target)
            {
                break;
            }
            if (Check(s, i + 1, ans + sum, target))
            {
                return true;
            }
        }
        return false;
    }
    public int PunishmentNumber(int n)
    {
        int ret = 0;
        for (int i = 1; i <= n; i++)
        {
            string s = (i * i).ToString();
            if (Check(s, 0, 0, i))
            {
                // 是惩罚数
                // Console.Write("i " + i);
                // Console.WriteLine(" i*i " + i * i);
                ret += i * i;
            }
        }
        return ret;
    }
}
// @lc code=end

