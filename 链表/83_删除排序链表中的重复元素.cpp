/*给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。

示例 1:

输入: 1->1->2
输出: 1->2
*/

//只需要遍历一遍就可以，如果p->val=p->next->val,就可以删除一个

#include<iostream>

struct ListNode {
    int val;
    ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
};

class Solution{
public:
    ListNode*deleteDuplicates(ListNode*head)
    {
        ListNode*p1=head;
        ListNode*temp = nullptr;
        while(p1!=nullptr&&p1->next!=nullptr)
        {
            if(p1->val==p1->next->val)
            {
                temp = p1->next;
                p1->next=temp->next;
                delete temp;
            }else{
                p1=p1->next;
            }
        }
        return head;
    }


};