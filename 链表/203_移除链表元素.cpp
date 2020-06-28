/*
删除链表中等于给定值 val 的所有节点。

示例:

输入: 1->2->6->3->4->5->6, val = 6
输出: 1->2->3->4->5
*/


//遍历 找到值删除就行

#include<iostream>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode*removeElement(ListNode*head,int val){
        while(head!=nullptr&&head->val==val){
            ListNode*per=head;
            head=head->next;
            delete per;
        }//如果是头节点相等，就删除
        if(head==nullptr)
        {
            return nullptr;
        }
        ListNode*cur = head;
        while(cur->next!=nullptr){
            if(cur->next->val==val){
                //删除操作
                ListNode*per = cur->next;
                cur->next=per->next;
                delete per;
            }else{
                cur=cur->next;
            }
            return head;
        }
    }
};