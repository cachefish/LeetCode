/*
350. 两个数组的交集 II
给定两个数组，编写一个函数来计算它们的交集。

 

示例 1：

输入：nums1 = [1,2,2,1], nums2 = [2,2]
输出：[2,2]
示例 2:

输入：nums1 = [4,9,5], nums2 = [9,4,9,8,4]
输出：[4,9]
*/
#include<vector>
#include<unordered_set>
using namespace std;
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size()) return intersect(nums2,nums1);

        unordered_multiset<int> hash;
        for(auto x:nums1) hash.insert(x);
        vector<int> res;
        for(auto x:nums2){
            if(hash.count(x)>0)
            {
                res.push_back(x);
                unordered_multiset<int>::iterator it = hash.find(x);
                hash.erase(it);
            }
        }
        return res;
    }
};