/*
 * @lc app=leetcode.cn id=1399 lang=typescript
 *
 * [1399] 统计最大组的数目
 */

// @lc code=start
//计算数位和
function getSum(n: number): number {
    let sum = 0;
    while (n > 0) {
        sum += n % 10;
        n = Math.floor(n / 10);
    }
    return sum;
}
function countLargestGroup(n: number): number {
    let maxValue = 0;
    //数位哈希表
    let hashMap = new Map<number, number>();//key为位数和，value为个数
    for (let i = 1; i <= n; i++) {
        hashMap.set(getSum(i), (hashMap.get(getSum(i)) || 0) + 1);
        maxValue = Math.max(maxValue, hashMap.get(getSum(i)) || 0);
    }
    //计算哈希表中value为maxValue的个数
    let count = 0;
    for (let [key, value] of hashMap) {
        if (value === maxValue) {
            count++;
        }
    }
    return count;
};
// @lc code=end

console.log(countLargestGroup(2));