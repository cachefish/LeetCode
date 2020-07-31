/*
给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。

你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/two-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

//遍历数组 两数相加和target比较  暴力
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       vector<int> sum;
       for(int i = 0;i<nums.size();++i){
            for(int j = i;j<=nums.size();++j){
                if(nums[i]+nums[j]==target){
                    sum.push_back(i);
                    sum.push_back(j);
                }
            }
       }
       return sum;
    }
};

//.排序+双指针法
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        vector<int> temp;
        temp=nums;
        int n=temp.size();
       sort(temp.begin(),temp.end());
       int i=0,j=n-1;
       while(i<j){  
           if(temp[i]+temp[j]>target)j--;
          else if(temp[i]+temp[j]<target)i++;
          else break; 
       }
       if(i<j){
      for(int k=0;k<n;k++){
          if(i<n&&nums[k]==temp[i]){
              ans.push_back(k);
              i=n;
          }
         else if(j<n&&nums[k]==temp[j]){
              ans.push_back(k);
              j=n;
          }
          if(i==n&&j==n)return ans;
      }
      }
        return ans;
    }
};
//3.hash法,利用undered_map数组构造映射，遍历nums[i]时，看target-nums[i]是否存在hash表中即可
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
         unordered_map<int, int> record;
        for (int i = 0; i < nums.size(); i++)
        {
            int complement = target - nums[i];
            if (record.find(complement) != record.end()) {
                int res[2] = {i,record[complement]};
                return vector<int>(res,res+2);
            }
            record[nums[i]] = i;
        }
        throw invalid_argument("no solution");
    }
};

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> myhash;
		vector<int> out;
        /* 首先所有的数据哈希映射表 */
		for (int i = 0; i < nums.size(); i++) {
			myhash[nums[i]] = i;
		}

		for (int i = 0; i < nums.size(); i++) {
            /* 在这里 判断 如果 存在 target - nums[i] 对应的 值  并且这个值不是自己 */
            /*映射关系  key->value,  key:target - nums[i],  value:myhash[target - nums[i]]*/
			if (myhash[target - nums[i]] && (myhash[target - nums[i]] != i)) {
				out.push_back(i);
				out.push_back(myhash[target - nums[i]]);
				return out;
			}
		}

		return out;
	}
};

