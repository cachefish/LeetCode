/*
200. 岛屿数量
给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。

岛屿总是被水包围，并且每座岛屿只能由水平方向或竖直方向上相邻的陆地连接形成。

此外，你可以假设该网格的四条边均被水包围。
输入:
[
['1','1','1','1','0'],
['1','1','0','1','0'],
['1','1','0','0','0'],
['0','0','0','0','0']
]
输出: 1
*/

//dfs
#include<vector>
using namespace std;
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty()||grid[0].empty()) return 0;
        int n = grid.size(),m=grid[0].size();
        int res = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    res++;
                    dfs(grid,i,j);
                }
            }
        }
        return res;
    }

    void dfs(vector<vector<char>>&grid,int x,int y)
    {
        int dx[4] = {-1,0,1,0},dy[4]={0,1,0,-1};
        grid[x][y] = '0';
        for(int i =0;i<4;i++){
            int nx = x+dx[i],ny=y+dy[i];
            if(0<=nx&&nx<grid.size()&&0<=ny&&ny<grid[0].size()&&grid[nx][ny]=='1'){
                dfs(grid,nx,ny);
            }
        }
    }
};