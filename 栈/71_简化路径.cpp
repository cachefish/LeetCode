/*
以 Unix 风格给出一个文件的绝对路径，你需要简化它。或者换句话说，将其转换为规范路径。

在 Unix 风格的文件系统中，一个点（.）表示当前目录本身；此外，两个点 （..） 表示将目录切换到上一级（指向父目录）；两者都可以是复杂相对路径的组成部分。更多信息请参阅：Linux / Unix中的绝对路径 vs 相对路径

请注意，返回的规范路径必须始终以斜杠 / 开头，并且两个目录名之间必须只有一个斜杠 /。最后一个目录名（如果存在）不能以 / 结尾。此外，规范路径必须是表示绝对路径的最短字符串。

*/

//"" 空值，即什么都没有，会出现在"/a/b/**////**c/"这样的路径中。
//"." 一个点，即当前文件夹，会出现在"/a/b/**./**c/"这样的路径中。
//".."两个点，即上一层文件夹，会出现在"/a/b/**../**c/"这样的路径中。
//"zimu_123"类似这样的由数字字母下划线组成的文件夹名，这是最普遍的类型。

/*
设定一个栈stack<string>来存储当前的绝对路径，用一个字符串temp
来存储临时的子路径名，它只有可能是上面四种情况之一，然后从前到后
遍历题目给出的绝对路径中的所有字符，不是'/'时更新temp，即将当前
字符加到temp后面，遇到'/'符号时进行分情况讨论，如果temp是前两种
情况那么什么都不用做，如果是'..'，便将栈顶出栈，而之后的栈顶就相
当于回到了上一层文件夹，如果是文件夹名，入栈即可。
*/

#include<iostream>
#include<string>
#include<stack>
using namespace std;
class Solution {
public:
    string simplifyPath(string path) {
        stack<string> paths; //栈，存储路径
        int q = 0; //用来遍历path
        string temp = ""; //存储单个的子路径
        while(q <= path.size())
        {
            //如果path[q]是‘/’或者q是path的长度(考虑到最后一个目录后面可能没有斜杠的情况)
            if(path[q] == '/' || q==path.size()) 
            {
                if(temp == "." || temp.size() == 0)
                { //前两种情况，什么都不做
                }
                else if(temp == "..")
                {
                    if(!paths.empty()) //处理“从根目录向上一级是不可行的”这种情况
                    paths.pop(); //上一个文件夹，即出栈
                }
                else
                {
                    paths.push(temp); //正常情况，文件夹入栈
                }
                temp = ""; //将temp置空重新开始
                q++;
            }
            else //将temp更新
            {
                temp += path[q];
                q++;
            }
        }
        string result = ""; 
        if(paths.empty()) //如果只剩个根文件夹，特判一下直接输出
        return "/";
        while(!paths.empty())
        {
            result = '/' + paths.top() + result; //从后往前，依此添加路径，因为以斜杠开头，所以..
            paths.pop();
        }
        return result;
    }
};
