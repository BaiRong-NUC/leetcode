/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */
#include<vector>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>>ret;
    //递归回溯算法
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>path;
        backtrack(nums,path);
        return ret;
    }
    void backtrack(vector<int>&nums,vector<int>&path) {
        //结束条件
        if(path.size()==nums.size()){
            ret.push_back(path);
            return;
        }
        //所有可能的选择
        for(int i=0;i<nums.size();i++){
            //已经选择过的跳过
            if(find(path.begin(),path.end(),nums[i])!=path.end()){
                continue;
            }
            //做选择
            path.push_back(nums[i]);
            backtrack(nums,path);
            //撤销选择
            path.pop_back();
        }
    }
};
// @lc code=end

