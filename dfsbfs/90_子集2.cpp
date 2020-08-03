/*
90. 子集 II
给定一个可能包含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。

说明：解集不能包含重复的子集。

示例:

输入: [1,2,2]
输出:
[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
*/
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        dfs(nums,0);
        return ans;
    }

    void dfs(vector<int>&nums,int u)
    {
        if(u==nums.size()){
            ans.push_back(path);
            return;
        }
        //计算当前数字的个数
        int k =0;
        while(u+k<nums.size()&&nums[u+k]==nums[u]) k++;
        for(int i =0;i<=k;i++){
            dfs(nums,u+k);
            path.push_back(nums[u]);
        }   
        for(int i =0;i<=k;i++){
            path.pop_back();
        }
    }
};
