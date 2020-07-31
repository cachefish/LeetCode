/*
给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

示例 1:

输入: "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-substring-without-repeating-characters
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
/*
我们使用两个指针表示字符串中的某个子串（的左右边界）。
其中左指针代表着上文中「枚举子串的起始位置」，而右指针即为上文中的 r
在每一步的操作中，我们会将左指针向右移动一格，表示 我们开始枚举下一个字符作为起始位置，然后我们可以不断地向右移动右指针，但需要保证这两个指针对应的子串中没有重复的字符。在移动结束后，这个子串就对应着 以左指针开始的，不包含重复字符的最长子串。我们记录下这个子串的长度；
在枚举结束后，我们找到的最长的子串的长度即为答案
*/
#include<set>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        int l = 0,r=0,_max = 0;
        set<char> sc;
        while (r!=s.size())
        {
            /* code */
            if(sc.find(s[r])==sc.end()){
                sc.insert(s[r++]);
                _max = max(_max,r-1);
            }else{
                sc.erase(s[l++]);
            }
        }
    return _max;
    }
};
//hash
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       int begin = 0;
       int result =0;
       string word = "";
       int char_map[128] = {0};
       for(int i =0;i<s.length();i++){
           char_map[s[i]]++;
           if(char_map[s[i]]==1){
               word+=s[i];
               if(result<word.length()){
                   result = word.length();
               }
           }else{
               while(begin<i&&char_map[s[i]]>1){
                   char_map[s[begin]]--;
                   begin++;
               }
               word ="";
               for(int j=begin;j<=i;j++){
                   word+=s[j];
               }
           }
       } 
       return result;
    }
};