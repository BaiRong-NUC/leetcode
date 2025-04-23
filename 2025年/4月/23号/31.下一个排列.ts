/*
 * @lc app=leetcode.cn id=31 lang=typescript
 *
 * [31] 下一个排列
 */

// @lc code=start
/**
 Do not return anything, modify nums in-place instead.
 */
function nextPermutation(nums: number[]): void {
    // 从后往前找到第一个nums[i]<nums[i+1]的位置，然后从i+1位置开始往后找到比降序位置大的第一个数，交换这两个数，然后从i+1开始后面的数进行升序排序
    let i = nums.length - 2;
    while (i >= 0 && nums[i] >= nums[i + 1]) {
        i--;
    }
    //退出循环i可能为-1或为0 i==-1时，说明整个数组是降序的，直接进行升序排序即可
    if (i >= 0) {
        //从i+1开始，从后向前找第一个比num[i]大的数字
        let j = nums.length - 1;
        while (j > i && nums[j] <= nums[i]) {
            j--;
        }
        //交换nums[i]和nums[j]
        [nums[i], nums[j]] = [nums[j], nums[i]];
    }
    //从i+1开始，后面的数字是降序排列，转换成升序排序,找到大于原数字的最小数字，顺序表逆序
    let left = i + 1;
    let right = nums.length - 1;
    while (left < right) {
        [nums[left], nums[right]] = [nums[right], nums[left]];
        left++;
        right--;
    }
};
// @lc code=end

