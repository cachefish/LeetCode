/*
9. 回文数
判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。
*/

//利用% /
class Solution
{
private:
    long long result = 0;//反转的结果
    int remainder = 0;//余数

public:
    bool isPalindrome(int x)
    {
        int temp = x;
        if (temp < 0)
            return false;
        while (temp != 0)
        {
            remainder = temp % 10;
            temp = temp / 10;
            result = result * 10 + remainder;
        }
        if ((int)result == x)
            return true;
        else
            return false;
    }
};
