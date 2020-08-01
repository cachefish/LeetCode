/*
26. 删除排序数组中的重复项
给定一个排序数组，你需要在 原地 删除重复出现的元素，使得每个元素只出现一次，
返回移除后数组的新长度。

不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的
条件下完成。
给定数组 nums = [1,1,2], 

函数应该返回新的长度 2, 并且原数组 nums 的前两个元素被修改为 1, 2。 

你不需要考虑数组中超出新长度后面的元素。

*/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()<2)
            return nums.size();
        int j = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[j]!=nums[i]){
                nums[++j]=nums[i];
            }
        }
        return ++j;
    }
};


class Solution1 {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        int cnt = 0; //统计当前元素需要前移的位数，注意还是计数排序思想！！！只不过不需要整个数组
        for(int i=1; i<size; ++i){
            if(nums[i] == nums[i-1])
                cnt++;
            nums[i-cnt] = nums[i]; //前移cnt个位置           
        }
        return size-cnt;
    }
};


int main()
{
    Solution sol;
    vector<int> nums{1,1,2};
    sol.removeDuplicates(nums);
    for(auto x:nums){
        std::cout <<x<<" ";
    }
}