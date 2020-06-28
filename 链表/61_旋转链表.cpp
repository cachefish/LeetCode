/*
给定一个链表，旋转链表，将链表每个节点向右移动 k 个位置，其中 k 是非负数。

示例 1:

输入: 1->2->3->4->5->NULL, k = 2
输出: 4->5->1->2->3->NULL
解释:
向右旋转 1 步: 5->1->2->3->4->NULL
向右旋转 2 步: 4->5->1->2->3->NULL

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/rotate-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

//相当于是将倒数k到结尾的节点接到头节点上，然后倒数k-1节点指向nullptr
//但是如果k的值大于节点数的话，k=5 n=4 就相当于k=1;所以要用k%count判断下

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
        ListNode*last = nullptr;
        int count =0;  //记录节点数
        while(pst!=nullptr){
            ++count;
            last = pst;
            pst = pst->next;
        }
        if(count == 0)
        {
            return head;
        }

        int actual = k%count;  //真正的移动
        last->next = head;  //头尾相连，形成环形链表
        pst=head;
        //找到count-actual-1位置的节点
        for(int i = 0;i<count-actual-1;++i)
        {
            pst = pst->next;
        }
        //让head指向新头节点
        head=pst->next;
        //断开链表
        pst->next = nullptr;
        
        return head;
    }
};