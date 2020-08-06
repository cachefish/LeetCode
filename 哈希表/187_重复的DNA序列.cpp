/*
187. 重复的DNA序列
所有 DNA 都由一系列缩写为 A，C，G 和 T 的核苷酸组成，例如：“ACGAATTCCG”。在研究 DNA 时，识别 DNA 中的重复序列有时会对研究非常有帮助。

编写一个函数来查找目标子串，目标子串的长度为 10，且在 DNA 字符串 s 中出现次数超过一次。

示例：

输入：s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
输出：["AAAAACCCCC", "CCCCCAAAAA"]
*/
#include<unordered_map>
#include<map>
#include<vector>
using namespace std;
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string,int> hash;
        vector<string> res;
        for(int i =0;i+10<=s.size();i++){
            string str = s.substr(i,10);
            if(++hash[str]==2) res.push_back(str);
        }
        return res; 

    }
};

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        map<string,int> word_map;
        vector<string> result;
        for(int i=0;i<s.length();i++){
            string word = s.substr(i,10);
            if(word_map.find(word)!=word_map.end()){
                word_map[word]+=1;
            }else
            {
                word_map[word] = 1;
            }
        }
        map<string,int> ::iterator it;
        for(it=word_map.begin();it!=word_map.end();it++){
            if(it->second>1){
                result.push_back(it->first);
            }
        }
        return result;
    }
};