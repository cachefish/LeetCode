//反转一个单链表。

//基本操作
#include<iostream>
 
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode*pre = NULL;
        ListNode*cur = head;
        while(cur!=NULL)
        {
            ListNode*next = cur->next;

            cur->next=pre;
            pre=cur;
            cur=next;
        }
        return pre;
    }
};