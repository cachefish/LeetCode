/*
给定两个大小为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。
请你找出这两个正序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。
你可以假设 nums1 和 nums2 不会同时为空。
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/median-of-two-sorted-arrays
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

//O(log(m+n))  二分
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
  //转为寻找第k小数问题
int find(vector<int>& nums1, int i, vector<int>& nums2, int j, int k){//从nums1中的i和nums2的j开始 找第k大的数
    if(nums1.size() - i > nums2.size() - j) return find(nums2, j, nums1, i, k);//保证第二个大于等于第一个
    if(nums1.size() == i) return nums2[j+k-1];//第一个数组为空时 
    if(k==1) return min(nums1[i],nums2[j]);//递归边界 即为两个最小值
    int si = min(int(nums1.size()),i + k/2), sj = j + k - k/2;//每个数组从起点开始的第k/2大数的后一个数的下标
    if(nums1[si-1] > nums2[sj-1]){//若前者的该数大于后者的该数 则后者的前部分就没用了
        return find(nums1, i, nums2, sj, k - (sj-j));//sj-j即为删去的数的个数
    }
    else return find(nums1, si, nums2, j, k - (si - i));//同理 此时 前者的前部分就没用了
}
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int tot = nums1.size() + nums2.size();
    if(tot % 2) {//总数为奇数时的中位数
        return find(nums1, 0, nums2, 0, tot/2+1);
    }
    else {
        int l = find(nums1, 0, nums2, 0, tot/2), r = find(nums1, 0, nums2, 0, tot/2 + 1);
        return (l + r)/2.0;
    }
}
};

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int total = nums1.size() + nums2.size();
        int mid = (total >> 1) + 1;
        const int* p1_end = nums1.data() + nums1.size();
        const int* p2_end = nums2.data() + nums2.size();
        const int *p1 = nums1.data(), *p2 = nums2.data();
        int v1 = 0, v2 = 0;

        for(int i = 0; i < mid; ++i){
            v1 = v2;
            if(p1 < p1_end && p2 < p2_end){
                if(*p1 < *p2){
                    v2 = *p1++;
                }else{
                    v2 = *p2++;
                }
            }else if(p1 < p1_end){
                v2 = *p1++;
            }else{
                v2 = *p2++;
            }
        }

        if(total % 2 == 0){
            // even
            return (v1 + v2) * 0.5;
        }else{
            // odd
            return v2;
        }
    }
};


class Solution {
public:
    double middle(vector<int> &nums){
        int n = nums.size();
        if (n == 0) return 0;
        if (n & 1) return nums[n/2];
        return (nums[n/2-1]+nums[n/2])/2.0;
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.empty()) return middle(nums2);
        if(nums2.empty()) return middle(nums1);
        if(nums1.size() > nums2.size()){ // 保证nums1.size() <= nums2.size()
            return findMedianSortedArrays(nums2, nums1);
        }
        int m = nums1.size(), n = nums2.size();
        int slice_left = 0, slice_right = m;
        int k = (m+n+1)/2;
        while(slice_left < slice_right){
            int slice_1 = slice_left + (slice_right-slice_left)/2;
            int slice_2 = k-slice_1;
            if(slice_2 <= 0) break;
            if(nums1[slice_1] < nums2[slice_2-1]) slice_left = slice_1+1;
            else slice_right = slice_1;
        }
        int slice_1 = slice_left, slice_2 = k - slice_1;
        // cout << slice_1 << " " << slice_2 << endl;
        int leftMax, rightMin;
        if(slice_1 == 0){
            leftMax = nums2[slice_2-1];
        }else if(slice_2 == 0){
            leftMax = nums1[slice_1-1];
        }else{
            leftMax = max(nums1[slice_1-1], nums2[slice_2-1]);
        }
        if(slice_1 == m){
            rightMin = nums2[slice_2];
        }else if(slice_2 == n){
            rightMin = nums1[slice_1];
        }else{
            rightMin = min(nums1[slice_1], nums2[slice_2]);
        }

        double ans = ((m+n)&1)?leftMax:((leftMax+rightMin)/2.0);
        return ans;
    }
};

