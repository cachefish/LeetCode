/*
给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。

k 是一个正整数，它的值小于或等于链表的长度。

如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-nodes-in-k-group
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/

//每次找到前k个节点后，进行翻转，再找下一次的节点

#include<iostream>
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};

class Solution{
public:
    ListNode*reverseList(ListNode*head,ListNode*tail){
        ListNode*pPrev = tail;
        ListNode*pCurr = head;
        while(pCurr!=tail){
            ListNode*pNext = pCurr->next;
            pCurr->next = pPrev;
            pPrev=pCurr;
            pCurr=pNext;
        }
        return pPrev;
    }
    ListNode*reverseKGroup(ListNode*head,int k)
    {
        ListNode*dummy = new ListNode(0);
        dummy->next = head;
        ListNode*pPrev = dummy;
        ListNode*pCurr = head;
        while(pCurr!=nullptr)
        {
            int i=0;
            //找到k位置节点
            while(i++<k&&pCurr!=nullptr)
            {
                pCurr=pCurr->next;  
            }
            if(i!=k+1) break;

            ListNode*pTemp = pPrev->next;
            pPrev->next = reverseList(pTemp,pCurr);//进行翻转
            pPrev=pTemp;//重新指向
        }
        return dummy->next;
    }
};

