/*
77. 组合
给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。

示例:

输入: n = 4, k = 2
输出:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> ans;

    vector<vector<int>> combine(int n, int k) {
        vector<int> path;
        dfs(path,1,n,k);    
        return ans;
    }

    void dfs(vector<int>&path,int start,int n,int k){
        if(!k){
            ans.push_back(path);
            return;
        }
        for(int i=start;i<=n;i++){
            path.push_back(i);
            dfs(path,i+1,n,k-1);
            path.pop_back();
        }
    }
};