/*
编写一个程序，找到两个单链表相交的起始节点。
*/


//A、B相遇，如果有交点总会有相遇的
#include<iostream>

struct ListNode {
     int val;
     ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};

class Solution{
public:
    ListNode*getIntersectionNode(ListNode*headA,ListNode*headB)
    {
        auto a = headA,b=headB;
        while(a!=b){
            if(a) a=a->next;
            else a=headB;
            if(b) b = b->next;
            else b=headA;
        }
        return b;
    }

};
