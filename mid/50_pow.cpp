/*
50. Pow(x, n)
实现 pow(x, n) ，即计算 x 的 n 次幂函数。

示例 1:

输入: 2.00000, 10
输出: 1024.00000
*/

class Solution {
public:
    double myPow(double x, int n) {
        if(n==0) return 1;
        double half = myPow(x,n/2);
        if(n%2==0) return half*half;
        if(n>0) return half*half*x;
        else return half*half/x;
    }
};