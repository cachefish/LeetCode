/*
对链表进行插入排序。
*/

//单纯的使用插入排序，比较val就可以,遍历一遍

#include<iostream>
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};


class Solution
{
public:
    ListNode*insertionSortList(ListNode*head){
        ListNode*dummy = new ListNode(-1);
        while(head){
            ListNode*p = dummy;
            while(p->next&&p->next->val<head->val){
                p=p->next;
            }
            ListNode*q = head;
            head=head->next;
            q->next=p->next;
            p->next=q;
        }
        return dummy->next;
    }


};

