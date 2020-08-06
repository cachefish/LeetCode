/*
162. 寻找峰值
峰值元素是指其值大于左右相邻值的元素。

给定一个输入数组 nums，其中 nums[i] ≠ nums[i+1]，找到峰值元素并返回其索引。

数组可能包含多个峰值，在这种情况下，返回任何一个峰值所在位置即可。

你可以假设 nums[-1] = nums[n] = -∞。

示例 1:

输入: nums = [1,2,3,1]
输出: 2
解释: 3 是峰值元素，你的函数应该返回其索引 2。
*/
#include<vector>
using namespace std;
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size()==1||nums[0]>nums[1]) return 0;
        int l = 1,r = nums.size()-1;
        while(l<r)
        {
            int mid = l+r+1 >> 1;
            if(nums[mid]>nums[mid-1]) l=mid;
            else r = mid-1;
        }
        return r;
    }
};