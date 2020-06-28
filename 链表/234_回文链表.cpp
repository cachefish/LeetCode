//请判断一个链表是否为回文链表。

//找到链表中点后，将后部分翻转，跟前部分一一比较

#include<iostream>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    bool isPalidrome(ListNode*head)
    {
        ListNode *slow = head,*fast = head,*prev = nullptr;
        //找中点
        while(fast&&fast->next){
            slow=slow->next;
            fast = fast->next->next;
        }
        //翻转
        while(slow){
            ListNode *temp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = temp;
        }
        //判断
        while(head&&prev){
            if(head->val!=prev->val){
                return false;
            }
            head=head->next;
            head=prev->next;
        }
        return true;
    }

};