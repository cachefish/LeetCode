/*
剑指 Offer 03. 数组中重复的数字
找出数组中重复的数字。

在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。
数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个
数字重复了几次。请找出数组中任意一个重复的数字。
输入：
[2, 3, 1, 0, 2, 5, 3]
输出：2 或 3 
*/

//原地移位法
//也可以先排序，再比较
#include<vector>
using namespace std;
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int n = nums.size();
        for(auto x:nums){
            if(x<0||x>=n)
                return -1;
        }
        for(int i=0;i<n;i++){
            while(i!=nums[i]&&nums[nums[i]]!=nums[i])
                swap(nums[i],nums[nums[i]]);
            if(nums[i]!=i&&nums[nums[i]]==nums[i]) return nums[i];

        }
        return -1;
    }
};