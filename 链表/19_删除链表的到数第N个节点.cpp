/*
给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。

示例：

给定一个链表: 1->2->3->4->5, 和 n = 2.

当删除了倒数第二个节点后，链表变为 1->2->3->5.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

//双指针锁定位置  一个指针先走n步，然后两个指针同时走，直到走到结尾，然后操作指针删掉节点

#include<iostream>

struct ListNode {
    int val;
    ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
};

class Solution{
public:
    ListNode*removeNthFromEnd(ListNode*head,int n)
    {
        
        ListNode*dumyhead = new ListNode(0); 
        dumyhead->next = head;
        ListNode * p = dumyhead;
        ListNode * q = dumyhead;
        for(int i = 0;i<n+1;i++)
        {
            if(q){
                q=q->next;
            }
        }
        while(q!=nullptr){
            p=p->next;
            q=q->next;
        }
        //开始操作删除节点
        ListNode*del = p->next;
        p->next = del->next;
        delete del;

        ListNode*retNode = dumyhead->next;
        delete dumyhead;
        return retNode;
    }

};

