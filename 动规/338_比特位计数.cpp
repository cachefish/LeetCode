/*
338. 比特位计数
给定一个非负整数 num。对于 0 ≤ i ≤ num 范围中的每个数字 i ，计算其二进制数中的 1 的数目并将它们作为数组返回。

示例 1:

输入: 2
输出: [0,1,1]
示例 2:

输入: 5
输出: [0,1,1,2,1,2]
*/
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res(num+1,0);
        for(int i =1;i<=num;i++){
            res[i] = res[i&(i-1)]+1;
        }
        return res;
    }
};