/*
53. 最大子序和
给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

示例:

输入: [-2,1,-3,4,-1,2,1,-5,4]
输出: 6
解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
*/
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int>dp(nums.size(),0);
        dp[0] = nums[0];
        int max_res = dp[0];
        for(int i = 1;i<nums.size();i++)
        {
            dp[i] = max(dp[i-1]+nums[i],nums[i]);
            if(max_res<dp[i]){
                max_res = dp[i];
            }
        }
        return max_res;
    }
};