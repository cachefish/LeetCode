/*
给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
示例:

输入: [0,1,0,2,1,0,1,3,2,1,2,1]
输出: 6
*/

//好难、、

/*
暴力破解  算法
假设输入为 [0,1,0,2]，只有下标 2 的上方可以接到雨水，其他地方的水会向两边“流掉”，所以无法接到水。

看下标 1 ，它左边最高的柱子是下标 0 ，右边最高的柱子是下标 3 ，因为这两个柱子的较小值比下标 1 要低，所以下标 1 的上方没有水。相反，我们看下标 2，它左边最高的柱子是下标 1 ，右边最高的柱子是下标 3 ，这两个柱子较矮的是下标 1 ，它比下标 2 本身要高，所以下标 2 可以接到水，接的水就是高度差。

因此，我们遍历每个下标，寻找它左边和右边最高的柱子，判断是否可以接到水，将可接水的结果累加即可。

*/

#include<iostream>
#include<vector>
#include<stack>
using namespace std;
class Solution
{
public:
#if 0
    int tarp(vector<int>&height)
    {
        int ans = 0;
        int n = height.size();
        int maxleft;
        int maxright;
        for(int i =0;i<n;i++)
        {
            maxleft =maxright=0;
            for(int j = 0;j<i;j++){
                maxleft = std::max(maxleft,height[j]);
            }
            for(int k=i;k<n;k++){
                maxright = std::max(maxright,height[k]);
            }
            if(std::min(maxleft,maxright)>height[i]){
                ans+=std::min(maxleft,maxright)-height[i];
            }
        }
        return ans;
    }
#endif
    int trap(vector<int>& height)
{
    int ans = 0, current = 0;
    stack<int> st;
    while (current < height.size()) {
        while (!st.empty() && height[current] > height[st.top()]) {
            int top = st.top();
            st.pop();
            if (st.empty())
                break;
            int distance = current - st.top() - 1;
            int bounded_height = min(height[current], height[st.top()]) - height[top];
            ans += distance * bounded_height;
        }
        st.push(current++);
    }
    return ans;
}

};