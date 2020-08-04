/*
402. 移掉K位数字
给定一个以字符串表示的非负整数 num，移除这个数中的 k 位数字，使得剩下的数字最小。
注意:
num 的长度小于 10002 且 ≥ k。
num 不会包含任何前导零。
示例 1 :
输入: num = "1432219", k = 3
输出: "1219"
解释: 移除掉三个数字 4, 3, 和 2 形成一个新的最小的数字 1219
*/
#include<string>
using namespace std;
class Solution {
public:
    string removeKdigits(string num, int k) {
        string res;
        for(char c:num)
        {
            while(res.size()&&res.back()>c&&k){
                res.pop_back();
                k--;
            }
            res+=c;
        }
        while(k--) res.pop_back();
        int i =0;
        while(i<res.size()&&res[i]=='0') i++;
        if(i==res.size()) return "0";
        return res.substr(i);
    }
};