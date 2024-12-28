/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

#include<iostream>
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // dp[i]代表金额为i时的最少硬币数
        vector<int>dp(amount+1,amount+1);
        dp[0]=0;
        for(int i=0;i<dp.size();i++){
            for(auto&coin:coins){
                if(i-coin<0){
                    continue;
                }
                else{
                    dp[i]=min(dp[i],dp[i-coin]+1);
                }
            }
        }
        return dp[amount]==amount+1?-1:dp[amount];
    }
};
// @lc code=end