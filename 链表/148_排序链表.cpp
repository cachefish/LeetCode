/*
在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序。

*/

//要求O(nlogn)时间复杂度的排序，故用归并排序

#include<iostream>
 
struct ListNode {
     int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

class Solution{
public:
    ListNode*sortList(ListNode*head)
    {
        return mergeSort(head);
    }
    ListNode*mergeSort(ListNode*node)
    {
        if(!node||node->next) return node;

        ListNode*fast = node;
        ListNode*slow = node;
        ListNode*temp = node;
        //找中点，断链表
        while(fast&&fast->next){
            fast=fast->next->next;
            temp = slow;
            slow=slow->next;
        }
        temp->next = nullptr;

        ListNode*l1 = mergeSort(node);
        ListNode*l2 = mergeSort(slow);
        return merge(l1,l2);

    }
    ListNode*merge(ListNode*l1,ListNode*l2)
    {
        if(l1==nullptr) return l2;
        if(l2==nullptr) return l1;
        if(l1->val<=l2->val){
            l1->next = merge(l1->next,l2);
        }else{
            l2->next =merge(l2->next,l1);
            return l2;
        }
    }
 };