/*
47. 全排列 II
给定一个可包含重复数字的序列，返回所有不重复的全排列。

示例:

输入: [1,1,2]
输出:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]
*/
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int n;
    vector<vector<int>> ans;
    vector<int> path;
    vector<bool> st;

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        n = nums.size();
        st = vector<bool>(n);
        path = vector<int>(n);
        sort(nums.begin(),nums.end());
        dfs(nums,0,0);
        return ans;
    }

    void dfs(vector<int>&nums,int u,int start)
    {
        if(u==n){
            ans.push_back(path);
            return;
        }
        for(int i=start;i<n;i++){
            if(!st[i]){
                st[i]=true;
                path[i]=nums[u];
                dfs(nums,u+1,u+1<n&&nums[u+1]==nums[u]?i+1:0);
                st[i]=false;
            }
        }
    }
};