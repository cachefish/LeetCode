/*
42. 接雨水
给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。



上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 感谢 Marcos 贡献此图。

示例:

输入: [0,1,0,2,1,0,1,3,2,1,2,1]
输出: 6
*/
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        int ans =0;
        int size = height.size();
        for(int i =1;i<size-1;i++) {
            int max_left = 0,max_right = 0;
            for (int j = i;j>=0;j--)
            {
                max_left=max(max_left,height[j]);
            }
            for(int j =i;j<size;j++)
            {
                max_right=max(max_right,height[j]);
            }
            ans +=min(max_left,max_right)-height[i];
        }
        return ans;
    }

};

int trap(vector<int>& height)
{
    int ans = 0;
    stack<int> st;
    for (int i = 0; i < height.size(); i++)
    {
        while (!st.empty() && height[st.top()] < height[i])
        {
            int cur = st.top();
            st.pop();
            if (st.empty()) break;
            int l = st.top();
            int r = i;
            int h = min(height[r], height[l]) - height[cur];
            ans += (r - l - 1) * h;
        }
        st.push(i);
    }
    return ans;
}
