/*
 * @lc app=leetcode.cn id=354 lang=cpp
 *
 * [354] 俄罗斯套娃信封问题
 */
#include <D:/CppCode/leetcode/global/global.h>
// @lc code=start
class Solution
{
    /* 返回 nums 中 LIS 的长度 */
    int lengthOfLIS(vector<int> &nums)
    {
        int piles = 0, n = nums.size();
        vector<int> top(n, 0);
        for (int i = 0; i < n; i++)
        {
            // 要处理的扑克牌
            int poker = nums[i];
            int left = 0, right = piles;
            // 二分查找插入位置
            while (left < right)
            {
                int mid = (left + right) / 2;
                if (top[mid] >= poker)
                    right = mid;
                else
                    left = mid + 1;
            }
            if (left == piles)
                piles++;
            // 把这张牌放到牌堆顶
            top[left] = poker;
        }
        // 牌堆数就是 LIS 长度
        return piles;
    }

public:
    int maxEnvelopes(vector<vector<int>> &envelopes)
    {
        // 信封宽相同时，按照长度降序排列
        sort(envelopes.begin(), envelopes.end(), [](const vector<int> &a, const vector<int> &b)
             {
            //a[0]==b[0]时 a[1]>b[1] a的宽度大于b的宽度时不交换，实现了按照宽度降序
            //a[0]!=b[0]时 a[0]<b[0] a的长度小于b的宽度时不交换，实现了按照长度升序
            return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0]; });
        // vector<int> dp(envelopes.size(), 1); // dp[i]表示按照宽度计算的最长递增序列
        // for (int i = 0; i < envelopes.size(); i++)
        // {
        //     for (int j = 0; j < i; j++)
        //     {
        //         if (envelopes[j][1] < envelopes[i][1])
        //         {
        //             dp[i] = max(dp[i], dp[j] + 1);
        //         }
        //     }
        // }
        // return *max_element(dp.begin(), dp.end());
        vector<int> height(envelopes.size());
        for (int i = 0; i < envelopes.size(); i++)
        {
            height[i] = envelopes[i][1];
        }
        return lengthOfLIS(height);
    }
};
// @lc code=end
