/*
38. 外观数列
给定一个正整数 n（1 ≤ n ≤ 30），输出外观数列的第 n 项。

注意：整数序列中的每一项将表示为一个字符串。

「外观数列」是一个整数序列，从数字 1 开始，序列中的每一项都是对前一项的描述。前五项如下：

1.     1
2.     11
3.     21
4.     1211
5.     111221
*/
#include<string>
using namespace std;
class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        for(int i =0;i<n;i++){
            string ns = "";
            for(int j =0;j<s.size();){
                int u = j;
                while(u<s.size()&&s[u]==s[j]) u++;
                ns += to_string(u-j);
                ns += s[j];
                j = u;
            }
        }
    }

};

class Solution {
public:
    char ch[3]={'1','2','3'};
    string countAndSay(int n) {
        if(n>1)
        {
        string s=countAndSay(n-1);
        string temp;
        for(int j=0;j<s.size();j++)
            {
                int count=0;
                while(s[j]==s[j+1])
                {
                    count++;
                    j++;
                }
                temp+=ch[count];
                temp+=s[j];
            }
        return temp;    
        }
        else return "1";
    }
};