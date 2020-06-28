/*
给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。

你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
给定 1->2->3->4, 你应该返回 2->1->4->3.
要对链表进行操作  
*/

//这个题当时是使用两个指针进行操作，通过临时的指针对指针进行移动，然后交换操作

#include<iostream>
 struct ListNode {
     int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
class Solution
{
    ListNode*swapPairs(ListNode*head)
    {
        if(head==nullptr||head->next==nullptr)
            return head;  //确保可交换
        ListNode*p1 = head;
        ListNode*p2 = p1->next;

        p1->next = p2->next;
        p2->next = p1;
        head=p2;  //将前两个节点进行操作

        p1=head->next;
        p2=p1->next;
        while(p2!=nullptr||p2->next!=nullptr)
        {
            //通过自己画图总结出每次交换的规律
            ListNode *temp = p1;
            p1=p2->next;
            p2->next = p1->next;
            p1->next=p2;
            temp->next = p1;
            //重新指向
            p1=p2;
            p2=p2->next;
        }
        return head;

    }
};