/*
784. 字母大小写全排列
给定一个字符串S，通过将字符串S中的每个字母转变大小写，我们可以获得一个新的字符串。返回所有可能得到的字符串集合。

示例:
输入: S = "a1b2"
输出: ["a1b2", "a1B2", "A1b2", "A1B2"]

输入: S = "3z4"
输出: ["3z4", "3Z4"]

输入: S = "12345"
输出: ["12345"]
*/
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    void DFS(int i,string S,vector<string>& res){
        if(i>=S.length()){
            res.push_back(S);
            return;
        }
        if(S[i]>='A' && S[i]<='Z'){
            S[i]+=32; //改变
            DFS(i+1,S,res);
            S[i]-=32; //变回来
            DFS(i+1,S,res);
        }else if(S[i]>='a' && S[i]<='z'){
            S[i]-=32;
            DFS(i+1,S,res);
            S[i]+=32;
            DFS(i+1,S,res);
        }
        else DFS(i+1,S,res);//数字跳过
    }
    vector<string> letterCasePermutation(string S) {
        vector<string> res;
        DFS(0,S,res);
        return res;
    }
};


class Solution {
public:
    vector<string> ans;
    vector<string> letterCasePermutation(string S) {
        dfs(S,0);
        return ans;
    }

    void dfs(string S,int u){
        if(u==S.size()){
            ans.push_back(S);
            return;
        }
        dfs(S,u+1);
        if(S[u]>='A')
        {
            //'A'  65
            //'a'  97
            S[u]^=32;
            dfs(S,u+1);
        }

    }
};