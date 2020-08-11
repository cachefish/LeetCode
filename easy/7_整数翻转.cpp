/*
7. 整数反转
给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。
*/
//取个位%10，存到y中，然后去掉各位/10

#include<iostream>
using namespace std;
class Solution {
public:
    int reverse(int x) {
        if(x/10==0) return x;//个位数
        int y =0;
        while(x){
            if(y>INT_MAX||y<INT_MIN){
                return 0;
            }
            y*=10;
            y+=x%10;
            x/10;
        }
        return y;
    }
};
