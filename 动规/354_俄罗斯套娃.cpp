/*
354. 俄罗斯套娃信封问题
给定一些标记了宽度和高度的信封，宽度和高度以整数对形式 (w, h) 出现。当另一个信封的宽度和高度都比这个信封大的时候，这个信封就可以放进另一个信封里，如同俄罗斯套娃一样。

请计算最多能有多少个信封能组成一组“俄罗斯套娃”信封（即可以把一个信封放到另一个信封里面）。

说明:
不允许旋转信封。

示例:

输入: envelopes = [[5,4],[6,4],[6,7],[2,3]]
输出: 3 
解释: 最多信封的个数为 3, 组合为: [2,3] => [5,4] => [6,7]。
*/
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
   int maxEnvelopes(vector<vector<int>>& envelopes){
	if (envelopes.size() <= 1) return envelopes.size();
	sort(envelopes.begin(), envelopes.end(), [](const vector<int> &a, const vector<int> &b)
	{
		if (a[0] == b[0]) return a[1] > b[1];
		return a[0] < b[0];
	});

	int ans = 0;
	vector<int> vec(envelopes.size(), INT_MAX);
	for (auto &e : envelopes)
	{
		int low = 0;
		int high = envelopes.size() - 1;
		while (high > low)
		{
			int mid = low + (high - low) / 2;
			if (vec[mid] >= e[1]) high = mid;
			else low = mid + 1;
		}

		vec[low] = e[1];
		ans = max(ans, low);
	}
	return ans + 1;
}
};

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        //动态规划，一维数组
        sort(envelopes.begin(), envelopes.end());
        int n = envelopes.size(), total_max = 1;
        if(n <= 0)  return 0;
        vector<int> dp(n + 1);
        dp[0] = 1;
        for(int i = 1 ; i < n ; i++){
            int cur = 0;
            for(int j = 0 ; j < i ; j++){
                cur = max(cur, (envelopes[i][0] > envelopes[j][0] && envelopes[i][1] > envelopes[j][1]) ? dp[j] + 1: 1) ;
            }
            dp[i] = cur;
            total_max = max(dp[i] , total_max);
        }
        return total_max;
    }
};
