/*
78. 子集
给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。

说明：解集不能包含重复的子集。

示例:

输入: nums = [1,2,3]
输出:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/
#include<vector>
using namespace std;
class Solution {
private:
    vector<vector<int>> res;
    void dfs(vector<int>& nums, int index, vector<int>& s) {
        res.push_back(s);

        for (int i = index; i < nums.size(); ++i) {
            s.push_back(nums[i]);
            dfs(nums, i + 1, s);
            s.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> vec;
        dfs(nums, 0, vec);
        return res;
    }
};