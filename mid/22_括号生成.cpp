/*
22. 括号生成
数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。
输入：n = 3
输出：[
       "((()))",
       "(()())",
       "(())()",
       "()(())",
       "()()()"
     ]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/generate-parentheses
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include<map>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        generate("",n,n,result);
        return result;
    }
private:
    void generate(string item,int left,int right,vector<string>&result)
    {
        if(left==0&&right==0){
            result.push_back(item);
        }
        if(left>0){
            generate(item+'(',left-1,right,result);
        }
        if(left<right){
            generate(item+')',left,right-1,result);
        }
    }
};

class Solution {
public:
    vector<string> res;
    // 什么时候选左括号： 左括号的的数量 > 0
    // 什么时候选右括号： 右括号的数量>0 &&右括号的数量！=左括号的数量
    vector<string> generateParenthesis(int n) {
        string Path;
        generateParenthesisHelper(Path,n,n);
        return res;
    }

    void generateParenthesisHelper(string& Path, int left,int right){
        // 括号选完了 直接放入结果数组中 返回
        if(left == 0 && right == 0){
            res.push_back(Path);
            return;
        }
        // 括号没选完，但是剩下的左括号和右括号数量相同，只能选择左括号
        if(left == right){
            Path.push_back('(');
            generateParenthesisHelper(Path,left - 1,right);
            Path.pop_back();
        } 
        // 左右不相等且都还没选完 则两个都有可能选
        else if(left > 0 && right > 0){
            Path.push_back('(');
            generateParenthesisHelper(Path,left - 1,right);
            Path.pop_back();
            Path.push_back(')');
            generateParenthesisHelper(Path,left,right - 1);
            Path.pop_back();
        }
        // 右边选完了
        else if(left > 0){
            Path.push_back('(');
            generateParenthesisHelper(Path,left - 1,right);
            Path.pop_back();
        }
        // 左边选完了
        else{
            Path.push_back(')');
            generateParenthesisHelper(Path,left,right -1);
            Path.pop_back();
        }
    }
};