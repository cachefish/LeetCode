/*35. 搜索插入位置
给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。

你可以假设数组中无重复元素。

示例 1:

输入: [1,3,5,6], 5
输出: 2
*/
#include<vector>
using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int index= -1;
        int begin = 0;
        int end = nums.size()-1;
        while(index==-1){
            int mid = begin+end >> 1;
            if(target==nums[mid]){
                index = mid;
            }else if(target<nums[mid]){
                if(mid==0||target>nums[mid-1]){
                    index = mid;
                }
                end = mid-1;
            }else if(target>nums[mid]){
                if(mid==nums.size()-1||target<nums[mid+1])
                {
                    index = mid+1;
                }
                begin = mid+1;
            }
        }
        return index;
    }
};

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0, right = n - 1, ans = n;
        while (left <= right) {
            int mid = ((right - left) >> 1) + left;
            if (target <= nums[mid]) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};
