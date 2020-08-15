/*
49. 字母异位词分组
给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。

示例:

输入: ["eat", "tea", "tan", "ate", "nat", "bat"]
输出:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
*/
#include<vector>
#include<string>
#include<unordered_map>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
      unordered_map<string,vector<string>> hash;
        for(auto s:strs)
        {
            string rs = s;
            sort(s.begin(),s.end());
            hash[s].push_back(rs);
        }
        vector<vector<string>> res;
        for(auto &group:hash)
        {
            res.push_back(group.second);
        }
        return res;
    }
};