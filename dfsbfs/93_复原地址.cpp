/*
93. 复原IP地址
给定一个只包含数字的字符串，复原它并返回所有可能的 IP 地址格式。

有效的 IP 地址正好由四个整数（每个整数位于 0 到 255 之间组成），整数之间用 '.' 分隔。

 

示例:

输入: "25525511135"
输出: ["255.255.11.135", "255.255.111.35"]
*/
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    vector<string> ans;
    vector<string> restoreIpAddresses(string s) {
        string path;
        dfs(s,0,0,path);
        return ans;
    }

    void dfs(string&s,int u,int k,string path){
        if(u==s.size()){
            if(k==4){
                ans.push_back(path.substr(1));
            }
            return;
        }
        if(k>4) return;
        if(s[u]=='0') dfs(s,u+1,k+1,path+".0");
        else{
            for(int i =u,t=0;i<s.size();i++){
                t = t*10+s[i]-'0';
                if(t<256) dfs(s,i+1,k+1,path+'.'+to_string(t));
                else break;
            }
        }

    }
};