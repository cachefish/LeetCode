/*
134. 加油站
在一条环路上有 N 个加油站，其中第 i 个加油站有汽油 gas[i] 升。

你有一辆油箱容量无限的的汽车，从第 i 个加油站开往第 i+1 个加油站需要消耗汽油 cost[i] 升。你从其中的一个加油站出发，开始时油箱为空。

如果你可以绕环路行驶一周，则返回出发时加油站的编号，否则返回 -1。

说明: 

如果题目有解，该答案即为唯一答案。
输入数组均为非空数组，且长度相同。
输入数组中的元素均为非负数。
示例 1:

输入: 
gas  = [1,2,3,4,5]
cost = [3,4,5,1,2]

输出: 3
*/
#include<vector>
using namespace std;
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector<int> sum;
        for(int i =0;i<gas.size();i++){
            sum.push_back(gas[i]-cost[i]);
        }
        int count =0;
        for(int i=0;i<sum.size();i++){
            count+=sum[i];
        }
        if(count<0)return -1;

        int start =0;
        int all_gas = 0;
        for(int i =0;i<sum.size();i++){
            all_gas+=sum[i];
            if(all_gas<0){
                all_gas=0;
                start=i+1;
            }
        }
        if(start<sum.size()){
            return start;
        }
        return -1;
    } 
};