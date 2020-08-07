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
第一项是数字 1
描述前一项，这个数是 1 即 “一个 1 ”，记作 11
述前一项，这个数是 11 即 “两个 1 ” ，记作 21
描述前一项，这个数是 21 即 “一个 2 一个 1 ” ，记作 1211
描述前一项，这个数是 1211 即 “一个 1 一个 2 两个 1 ” ，记作 111221
*/
#include<string>
using namespace std;
class Solution {
public:
    string countAndSay(int n) {
      string s = "1";
      for(int i =1;i<n;i++)
      {
          string ns = "";
          for(int j =0;j<s.size();)
          {
              int u =j;
              while(u<s.size()&&s[u]==s[j]) u++;
              ns += to_string(u-j);
              ns += s[j];
              j=u;
          }
          s = ns;
      }  
      return s;
    }
};