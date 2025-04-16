/*
 * @lc app=leetcode.cn id=2537 lang=typescript
 *
 * [2537] 统计好子数组的数目
 */

// @lc code=start
function countGood(nums: number[], k: number): number {
    //滑动窗口
    let ret = 0;
    let map = new Map<number, number>();
    let same = 0;//相同元素的个数
    let right = -1;//右指针
    for (let left = 0; left < nums.length; left++) {
        while (right + 1 < nums.length && same < k) {
            right += 1;
            //记录存在相同元素的对数
            //如果map.get(nums[right])存在，说明之前已经有相同元素，那么就可以组成新的相同元素对
            same += map.get(nums[right]) || 0;
            // 相同元素的个数+1
            map.set(nums[right], (map.get(nums[right]) || 0) + 1);
        }
        if (same >= k) {
            /**
             * 当窗口满足条件时，计算从当前窗口开始到数组末尾的所有可能子数组
             * nums.length - right表示从当前右边界到数组末尾的元素数量
             * 这些元素都可以与当前窗口组成新的满足条件的子数组，因为它们都包含了至少k个相同元素
             */
            ret += nums.length - right;
        }
        //移动左窗口，删除左窗口的元素
        //防止map.get(nums[left])==undefined
        map.set(nums[left], (map.get(nums[left]) || 0) - 1);
        same -= map.get(nums[left]) || 0;
    }
    return ret;
};
// @lc code=end

