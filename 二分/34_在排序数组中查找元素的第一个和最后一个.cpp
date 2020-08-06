/*
34. 在排序数组中查找元素的第一个和最后一个位置
给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。

你的算法时间复杂度必须是 O(log n) 级别。

如果数组中不存在目标值，返回 [-1, -1]。

示例 1:

输入: nums = [5,7,7,8,8,10], target = 8
输出: [3,4]
*/
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty()) return {-1,-1};
        int left = 0,right = nums.size() - 1,lhsResult = 0;
        while(left < right)
        {
            int mid = (left + right) / 2;
            //第一次循环利用二分查找搜索第一个目标值出现的位置
            if(nums[mid] < target)
            {
                left  = mid + 1;
            }else
                right = mid;
        }
        if(nums[left] != target) return {-1,-1};
        lhsResult = left,right = nums.size();
        while(left < right)
        {
            int mid = (left + right) / 2;
            //第二次循环利用二分查找搜索最后一个目标值出现的位置
            if(nums[mid] <= target)
                left = mid + 1;
            else
                right = mid;
        }
        return {lhsResult,left - 1};     
    }
};