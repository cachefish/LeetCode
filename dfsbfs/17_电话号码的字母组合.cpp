/*
7. 电话号码的字母组合
给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
输入："23"
输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
*/

#include<map>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    map<char,string> M = {
        {'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}
    };
    vector<string> ans;
    string current;
    void DFS(int index,string digits){
        if(index==digits.size()){
            ans.push_back(current);
            return;
        }
        for(int i = 0;i<M[digits[index]].size();i++){
            current.push_back(M[digits[index]][i]);
            DFS(index+1,digits);
            current.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0){
            return ans;
        }
        DFS(0,digits);
        return ans;
    }
};

class Solution {
public:
    string chars[8]={"abc","def","ghi","jkl","mno",
    "pqrs","tuv","wxyz"};
    vector<string> letterCombinations(string digits) {
        if(digits.empty()){
            return vector<string>();
        }
        vector<string> state(1,"");
        for(auto u:digits){
            vector<string> now;
            for(auto c:chars[u-'2']){
                for(auto s:state){
                    now.push_back(s+c);  
                }
            }
            state=now;
        }
        return state;
    }
 };
