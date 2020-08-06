/*
347. 前 K 个高频元素
给定一个非空的整数数组，返回其中出现频率前 k 高的元素。

 

示例 1:

输入: nums = [1,1,1,2,2,3], k = 2
输出: [1,2]
示例 2:

输入: nums = [1], k = 1
输出: [1]
*/
#include<cstdio>
#include<unordered_map>
#include<vector>
#include<queue>
#include<assert.h>
using namespace std;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        assert(k>0);
        unordered_map<int,int> freq;
        for(int i=0;i<nums.size();i++)
        {
            freq[nums[i]]++;
        }
        assert(k<=freq.size());
        //扫描freq，维护当前出现频率最高的k个元素
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq; 
        for(unordered_map<int,int>::iterator iter=freq.begin();
        iter!=freq.end();iter++){
            if(pq.size()==k){
                if(iter->second>pq.top().first){
                    pq.pop();
                    pq.push(make_pair(iter->second,iter->first));
                }
            }else{
                pq.push(make_pair(iter->second,iter->first));
            }
        }
        vector<int> res;
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
    return res;
    }
};
