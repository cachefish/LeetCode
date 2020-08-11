/*
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
注意空字符串可被认为是有效字符串。


*/
//如果是左括号就入栈，如果是右括号就将这个右括号转化成该类型的左括号然后跟栈顶比较


#include<iostream>
#include<stack>
#include<string>
using std::string;
using std::stack;

class Solution
{
public:
    bool isVaild(string s){
        stack<char> st;
        for(int i =0;i<s.size();i++)
        {
            if(s[i]=='('||s[i]=='{'||s[i]=='[')
            {
                st.push(s[i]);
            }
            else{
                if(st.size()==0)
                    return false;
                char c = st.top();
                st.pop();

                char match;  //转换的左括号
                if(s[i]==')')
                {
                    match = '(';
                }else if(s[i]=='}')
                {
                    match = '{';
                }else if(s[i]==']')
                {
                    match = '[';
                }
                if(c!=match)   //每次跟栈顶元素比较
                {
                    return false;
                }
            }
        }
        if(st.size()!=0)
            return false;
        return true;
    }
};