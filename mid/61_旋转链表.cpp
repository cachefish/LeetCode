/*
61. 旋转链表
给定一个链表，旋转链表，将链表每个节点向右移动 k 个位置，其中 k 是非负数。

示例 1:

输入: 1->2->3->4->5->NULL, k = 2
输出: 4->5->1->2->3->NULL
解释:
向右旋转 1 步: 5->1->2->3->4->NULL
向右旋转 2 步: 4->5->1->2->3->NULL
*/

#include<iostream>

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode*rotateRight(ListNode*head,int k){
        ListNode*pst = head;
        ListNode*last = NULL;
        int count =0;
        while(pst != NULL){
            ++count;
            last = pst;
            pst=pst->next;
        }
        if(count==0){
            return head;
        }
        int actual = k%count;
        last->next = head;
        pst = head;
        for(int i=0;i<count-actual-1;++i){
            pst=pst->next;
        }
        head = pst->next;
        pst->next = NULL;
        return head;
    }
};