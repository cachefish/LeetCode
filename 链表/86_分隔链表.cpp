/*
给定一个链表和一个特定值 x，对链表进行分隔，使得所有小于 x 的节点都在大于或等于 x 的节点之前。

你应当保留两个分区中每个节点的初始相对位置。

示例:

输入: head = 1->4->3->2->5->2, x = 3
输出: 1->2->2->4->3->5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/partition-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/

//创建两个链表，节点小于c放在Llist中，大于x的放在Rlist中
//创建一个链表，然后遍历两次原链表
#include<iostream>

struct ListNode {
    int val;
    ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
};
#if 0
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
       //创建两个结点，用于保存<x的值和>=x的值
        ListNode *before=new ListNode(0);
        ListNode *after=new ListNode(0);
        //创建两个指针指向两个新建结点
        ListNode *p1=before,*p2=after;
        if(!head)
        return head;
        //遍历链表，<x的值连在before后面，>=x的值连在after后面
        while(head)
        {
            if(head->val<x)
            {
                p1->next=head;
                p1=p1->next;
                head=head->next;
            }
            else
            {
                p2->next=head;
                p2=p2->next;
                head=head->next;
            }
        }
        //将before和after连起来
        p2->next=NULL;
        p1->next=after->next;
        return before->next;
    }
};

#endif
class Solution{
public:
    ListNode*partition(ListNode*head,int x)
    {
        ListNode*pre = new ListNode(-1);
        ListNode*res = pre;
        ListNode*old = head;
        while(old){
            int val = old->val;
            if(val<x){
                ListNode*new_node = new ListNode(val);
                pre->next=new_node;
                pre=pre->next;
            }
            old=old->next;
        }
        old=head;//再次遍历一次
        while(old){
            int val = old->val;
            if(val>=x){
                ListNode*new_node = new ListNode(val);
                pre->next=new_node;
                pre=pre->next;
            }
            old=old->next;
        }
        return res->next;
    }
};
