/*
55. 跳跃游戏
给定一个非负整数数组，你最初位于数组的第一个位置。

数组中的每个元素代表你在该位置可以跳跃的最大长度。

判断你是否能够到达最后一个位置。

示例 1:

输入: [2,3,1,1,4]
输出: true
解释: 我们可以先跳 1 步，从位置 0 到达 位置 1, 然后再从位置 1 跳 3 步到达最后一个位置。
*/

#include<vector>
using namespace std;
class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<int> index;
        for(int i =0;i<nums.size();i++)
        {
            index.push_back(i+nums[i]);
        }
        int jump = 0;
        int maxindex = index[0];
        while(jump<index[jump])
        {
            if(maxindex<index[jump]){
                maxindex = index[jump];
            }
            jump++;
        }
        if(jump==index.size()){
            return true;
        }else{
            return false;
        }
    }
};