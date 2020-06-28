/*
反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。

说明:
1 ≤ m ≤ n ≤ 链表长度。

示例:

输入: 1->2->3->4->5->NULL, m = 2, n = 4
输出: 1->4->3->2->5->NULL

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-linked-list-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

//先找到要反转的位置，然后直接反转就行，这个还是很简单的

#include<iostream>

struct ListNode {
    int val;
    ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode*reverseBetween(ListNode*head,int m,int n)
    {
        int length = n-m+1;
        ListNode*saveHead = nullptr;
        ListNode*saveTail;
        ListNode*ret = head;
        while(head&&--m){  //找到起始位置

            saveHead=head;
            head=head->next;
        }
        saveTail = head;
        ListNode*retHead = nullptr;
        while(head&&length--){
            ListNode*temp = head->next;
            head->next=retHead;
            retHead=head;
            head=temp;
        }
        saveTail->next = head;
        if(saveHead){
            saveHead->next=retHead;
        }else{
            ret = retHead;
        }
        return ret;
    }
};