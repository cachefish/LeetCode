/*
394. 字符串解码
给定一个经过编码的字符串，返回它解码后的字符串。

编码规则为: k[encoded_string]，表示其中方括号内部的 encoded_string 正好重复 k 次。注意 k 保证为正整数。

你可以认为输入字符串总是有效的；输入字符串中没有额外的空格，且输入的方括号总是符合格式要求的。

此外，你可以认为原始数据不包含数字，所有的数字只表示重复的次数 k ，例如不会出现像 3a 或 2[4] 的输入。

 

示例 1：

输入：s = "3[a]2[bc]"
输出："aaabcbc"
示例 2：

输入：s = "3[a2[c]]"
输出："accaccacc"
*/
#include<string>
using namespace std;
class Solution {
public:
    string decodeString(string s) {
        string res;
        for(int i =0;i<s.size();){
            if(!isdigit(s[i])) res+=s[i++];
            else{
                int k =0;
                while(isdigit(s[i])) k = k*10+s[i++]-'0';
                int j = i+1,sum=1;
                while(sum>0){
                    if(s[j]=='[') sum++;
                    if(s[j]==']') sum--;
                    j++;   
                }
                string r = decodeString(s.substr(i+1,j-i-2));
                while(k--) res += r;
                i=j;
            }
        }
        return res;
    }
};