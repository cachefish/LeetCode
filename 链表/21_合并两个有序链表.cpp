/*
将两个升序链表合并为一个新的 升序 链表并返回。
新链表是通过拼接给定的两个链表的所有节点组成的。
*/

//因为是两个升序链表，所以可以遍历 对比两个链表的值，然后生成新链表

#include<iostream>

struct ListNode {
     int val;
     ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

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
};