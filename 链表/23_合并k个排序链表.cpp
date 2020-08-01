//合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。


//方法一：从21的合并n个链表，可以复用代码，每次合并两个

#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct ListNode {
     int val;
     ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };
#if 0
/*
渐进时间复杂度为 O(k^2 n)O(k 2 n)

空间复杂度：没有用到与 kk 和 nn 规模相关的辅助空间，故渐进空间复杂度为 O(1)O(1)。
*/
class Solution{
public:
   ListNode* mergeTwoLists(ListNode*l1,ListNode*l2)
   {
       ListNode newHead(0);
       ListNode*p = &newHead;
       while(l1&&l2)
       {
           if(l1->val>l2->val){
                std::swap(l1,l2);
           } 
           p->next = l1;
           l1=l1->next;
           p = p->next;
       }
       p->next = l1?l1:l2;
       return newHead.next;
   }

    ListNode *mergeKLists(std::vector<ListNode*>&lists){
        ListNode*ans = nullptr;
        for(size_t i=0;i<lists.size();++i){
            ans = mergeTwoLists(ans,lists[i]);
        }
        return ans;
    }
};
#endif
//方法二  使用二分法 排序进行合并
class Solution
{
public:
    ListNode*mergeKLists(std::vector<ListNode*>&lists){
        ListNode*head = nullptr;
        if(lists.size()==0) return head;
        if(lists.size()==1) return lists[0];
        int len = lists.size();
        int low =0;
        int high = len-1;
        head = binarymerge(low,high,lists);
        return head;
    }
    ListNode*binarymerge(int low,int high,std::vector<ListNode*>&lists)
    {
        if(low==high)
            return lists[low];
        ListNode*left = nullptr;
        ListNode*right = nullptr;
        int mid = (low,high)/2;
        left = binarymerge(low,mid,lists);
        right = binarymerge(mid+1,high,lists);
        return mergeTwoLists(left,right);
    }
    ListNode*mergeTwoLists(ListNode*l1,ListNode*l2)
    {
        if(l1==nullptr) return l2;
        ListNode*L= nullptr;
        ListNode*tail = nullptr;
        if(l1->val<l2->val){
            L=l1;
            l1=l1->next;
        }else{
            tail->next = l2;
            l2=l2->next;
        }
        tail = L;
        while(l1&&l2){
            if(l1->val<l2->val){
                tail->next = l1;
                l1=l1->next;
            }else{
                tail->next = l2;
                l2=l2->next;
            }
            tail = tail->next;
        }
        while(l1){
            tail->next = l1;
            l1=l1->next;
            tail = tail->next;
        }
        while(l2){
            tail->next = l2;
            l2=l2->next;
            tail = tail->next;
        }
        return L;
    }

};
/*
class Solution {
public:
    // 小根堆的回调函数
    struct cmp{  
       bool operator()(ListNode *a,ListNode *b){
          return a->val > b->val;
       };
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> pri_queue;
        // 建立大小为k的小根堆
        for(auto elem : lists){
            if(elem) pri_queue.push(elem);
        }
        // 可以使用哑节点/哨兵节点
        ListNode dummy(-1);
        ListNode* p = &dummy;
        // 开始出队
        while(!pri_queue.empty()){
            ListNode* top = pri_queue.top(); pri_queue.pop();
            p->next = top; p = top;
            if(top->next) pri_queue.push(top->next);
        }
        return dummy.next;  
    }
};*/