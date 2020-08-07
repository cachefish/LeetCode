/*
151. 翻转字符串里的单词
给定一个字符串，逐个翻转字符串中的每个单词。

 

示例 1：

输入: "the sky is blue"
输出: "blue is sky the"
示例 2：

输入: "  hello world!  "
输出: "world! hello"
解释: 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
*/
#include<string>
using namespace std;
class Solution {
public:
    string reverseWords(string s) {
        if(s.empty()){
            return "";
        }
        string res = "";
        int right = s.size()-1;
        int left = right;
        while(left>=0){
            while(left>=0&&s[left]==' '){
                left--;
                right=left;
            }
            while(left>=0&&s[left]!=' '){
                left--;
            }
            if(left!=right){
                res+=s.substr(left+1,right-left)+" ";
            }
        }
        if(!res.empty()){
            res.pop_back();
        }
        return res;
    }
};

string reverseWords(string s) {
    reverse(s.begin(), s.end());                        //整体反转
    int start = 0, end = s.size() - 1;
    while (start < s.size() && s[start] == ' ') start++;//首空格
    while (end >= 0 && s[end] == ' ') end--;            //尾空格
    if (start > end) return "";                         //特殊情况

    for (int r = start; r <= end;) {                    //逐单词反转
        while (s[r] == ' '&& r <= end) r++;
        int l = r;
        while (s[l] != ' '&&l <= end) l++;
        reverse(s.begin() + r, s.begin() + l);
        r = l;
    }

    int tail = start;                                   //处理中间冗余空格
    for (int i = start; i <= end; i++) {
        if (s[i] == ' '&&s[i - 1] == ' ') continue;
        s[tail++] = s[i];
    }
    return s.substr(start, tail - start);
}
