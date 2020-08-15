/*
45. 跳跃游戏 II
给定一个非负整数数组，你最初位于数组的第一个位置。

数组中的每个元素代表你在该位置可以跳跃的最大长度。

你的目标是使用最少的跳跃次数到达数组的最后一个位置。

示例:

输入: [2,3,1,1,4]
输出: 2
解释: 跳到最后一个位置的最小跳跃数是 2。
     从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。
*/

#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()==1) return 0;
        int l =0,r=0,step =0;
        while(l<=r){
            int max_r = 0;
            for(int i =l;i<=r;i++){
                max_r = max(max_r,i+nums[i]);
            }
            l=r+1,r=max_r;
            step++;
            if(r>=(int)nums.size()-1) break;
        }
        return step;
    }
};