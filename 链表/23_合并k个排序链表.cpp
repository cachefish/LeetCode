//合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。


//方法一：从21的合并n个链表，可以复用代码，每次合并两个

#include<iostream>
#include<vector>
struct ListNode {
     int val;
     ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };
#if 0
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