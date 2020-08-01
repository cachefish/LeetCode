/*
15. 三数之和
给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有满足条件且不重复的三元组。

注意：答案中不可以包含重复的三元组。
给定数组 nums = [-1, 0, 1, 2, -1, -4]，

满足要求的三元组集合为：
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for(int i =0;i+2<nums.size();i++){
            if(nums[i]>0) break;

            if(i>0&&nums[i]==nums[i-1]) continue;

            int target = -nums[i];
            int l = i+1;
            int r = nums.size()-1;
            while(l<r){
                int sum = nums[l]+nums[r];
                if(sum==target){
                    res.push_back({nums[i],nums[l],nums[r]});
                    l++;
                    r--;
                    while(l<r&&nums[l]==nums[l-1]) l++;
                    while(l<r&&nums[r]==nums[r+1]) r--;
                }
                if(sum<target) l++;
                if(sum>target) r--;
            }
        }
        return res;
    }
};