/*
给定一个单链表 L：L0→L1→…→Ln-1→Ln ，
将其重新排列后变为： L0→Ln→L1→Ln-1→L2→Ln-2→…

你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

示例 1:

给定链表 1->2->3->4, 重新排列为 1->4->2->3.
示例 2:

给定链表 1->2->3->4->5, 重新排列为 1->5->2->4->3.
*/

//先找到中点结点，然后将后半部分进行反转，然后依次将后部分的结点进行插入

#include<iostream>
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
public:
    void reorderList(ListNode*head)
    {
        if(head==nullptr||head->next==nullptr)
        {
            return;
        }
        ListNode*slow = head;
        ListNode*fast = head;
        //找到中点
        while(fast->next&&fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        
        //后端反转
        ListNode*needReverser = slow->next;
        slow->next = nullptr;   //断链
        needReverser = reverse(needReverser);

        //插入每两结点中
        ListNode*cur = head;
        while(cur&&needReverser){
            //画图理解很好理解
            ListNode*curSecond = needReverser;
            needReverser = needReverser->next;
            ListNode*nextCur = cur->next;
            curSecond->next = cur->next;
            cur->next = curSecond;

            cur=nextCur;
        }

    }
    ListNode*reverse(ListNode*head)
    {
        ListNode*p1=nullptr;
        ListNode *p2 = head;
        ListNode*p3 = p2;
        while(p2){
            //画图理解
            p3=p2->next;
            p2->next = p1;
            p1=p2;
            p2=p3;
        }
        return p1;
    }
};