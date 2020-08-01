/*
剑指 Offer 12. 矩阵中的路径
请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。
路径可以从矩阵中的任意一格开始，每一步可以在矩阵中向左、右、上、下移动一格。
如果一条路径经过了矩阵的某一格，那么该路径不能再次进入该格子。例如，在下面的
3×4的矩阵中包含一条字符串“bfce”的路径（路径中的字母用加粗标出）。
[["a","b","c","e"],
["s","f","c","s"],
["a","d","e","e"]]
但矩阵中不包含字符串“abfb”的路径，因为字符串的第一个字符b占据
了矩阵中的第一行第二个格子之后，路径不能再次进入这个格子。
输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
输出：true

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/ju-zhen-zhong-de-lu-jing-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    int x[4] = {0,0,-1,1}; //x[4]、y[4]和dfs中for循环，共同构成遍历字符board[i][j]的“左右上下”四个字符这一功能
    int y[4] = {-1,1,0,0}; // 这里用的特别巧妙
    int rows,cols;
    bool dfs(vector<vector<char>>& board,string word,int i,int j,int num) {
        if (num == word.size()) return true;
        char tmp = board[i][j]; // 用于暂时保存字符
        board[i][j] = '.'; // 代表这个字符已经访问过
        for (int k = 0; k < 4; k++) {
            int d_x = x[k] + i; // 新的i值
            int d_y = y[k] + j; // 新的j值
            if (d_x >= 0 && d_x < rows && d_y >= 0 && d_y < cols && word[num] == board[d_x][d_y]) {
                if (dfs(board,word,d_x,d_y,num + 1)) return true;
            }
        }
        board[i][j] = tmp; // 遍历结束后改回来
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        rows = board.size();
        cols = board[0].size();
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == word[0]) {
                    if (dfs(board,word,i,j,1)) return true;
                }
            }
        }
        return false;
    }
};