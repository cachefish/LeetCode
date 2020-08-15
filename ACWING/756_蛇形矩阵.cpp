/*
输入两个整数n和m，输出一个n行m列的矩阵，将数字 1 到 n*m 按照回字蛇形填充至矩阵中。

具体矩阵形式可参考样例。

输入格式
输入共一行，包含两个整数n和m。

输出格式
输出满足要求的矩阵。

矩阵占n行，每行包含m个空格隔开的整数。

数据范围
1≤n,m≤100
输入样例：
3 3
输出样例：
1 2 3
8 9 4
7 6 5
*/

#include<iostream>
#include<algorithm>

using namespace std;

const int N = 110;

int n,m;
int res[N][N];
bool st[N][N];

int main()
{
    cin>>n>>m;
    
    int dx[]={0,1,0,-1},dy[]={1,0,-1,0};
    int x=0,y=0,d=0;
    for(int i =1;i<=n*m;i++)
    {
        int nx = x +dx[d],ny = y +dy[d];
        if(nx<0||nx>=n||ny<0||ny>=m||st[nx][ny])
        {
            d = (d+1)%4;
            nx = x +dx[d],ny = y+dy[d];
        }
        res[x][y] = i;
        st[x][y] = true;
        
        x = nx, y =ny;
    }
    for(int i =0;i<n;i++)
    {
        for(int j =0;j<m;j++) cout<<res[i][j]<<" ";
        cout<<endl;
    }
    return 0;

}