/*
120. 三角形最小路径和
给定一个三角形，找出自顶向下的最小路径和。每一步只能移动到下一行中相邻的结点上。

相邻的结点 在这里指的是 下标 与 上一层结点下标 相同或者等于 上一层结点下标 + 1 的两个结点。

 

例如，给定三角形：

[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
*/
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> f(triangle[n-1].begin(),triangle[n-1].end()),g(n);

        for(int i =n-2;i >= 0;i--){
            for(int j =0;j<=i;j++){
                g[j]=min(f[j],f[j+1])+triangle[i][j];
            }
            f = g;
        }
        return f[0];
    }
};

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for(int i=triangle.size()-2;i>=0;i--)
            for(int j =0;j<triangle[i].size();j++)
                triangle[i][j]+=min(triangle[i+1][j],triangle[i+1][j+1]);
            return triangle[0][0];
    }
};