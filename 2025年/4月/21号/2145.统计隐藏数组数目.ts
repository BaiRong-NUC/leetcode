/*
 * @lc app=leetcode.cn id=2145 lang=typescript
 *
 * [2145] 统计隐藏数组数目
 */

// @lc code=start
function numberOfArrays(differences: number[], lower: number, upper: number): number {
    //前缀和
    let hideni = 0;//隐藏数组的第一个元素
    let min = 0;//隐藏数组的最小值
    let max = 0;//隐藏数组的最大值
    differences.forEach(diff => {
        //hiden[i]=hiden[i-1]+diff[i-1] i从1开始
        hideni += diff;
        min = Math.min(min, hideni);
        max = Math.max(max, hideni);
    });
    return Math.max(0, upper - lower - (max - min) + 1);
};
// @lc code=end

