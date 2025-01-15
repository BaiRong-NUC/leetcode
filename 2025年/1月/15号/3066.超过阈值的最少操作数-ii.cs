/*
 * @lc app=leetcode.cn id=3066 lang=csharp
 *
 * [3066] 超过阈值的最少操作数 II
 */

// @lc code=start
public class Solution
{
    public int MinOperations(int[] nums, int k)
    {
        int ret = 0;
        if (nums.Length == 1)
        {
            return nums[0] >= k ? 0 : 1;
        }
        //利用优先级队列模拟小堆
        PriorityQueue<long, long> pq = new PriorityQueue<long, long>();
        foreach (int num in nums)
        {
            //权值是第二个参数，为自己本身实现优先级队列
            pq.Enqueue(num, num);
        }
        //堆顶是最小元素
        while (pq.Peek() < k)
        {
            //取出两个最小元素
            long x = pq.Dequeue();
            long y = pq.Dequeue();
            pq.Enqueue(x * 2 + y, x * 2 + y);
            ret++;
        }
        return ret;
    }
}
// @lc code=end