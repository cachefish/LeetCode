/*

给定一个单链表，把所有的奇数节点和偶数节点分别排在一起。请注意，这里的奇数节点和偶数节点指的是节点编号的奇偶性，而不是节点的值的奇偶性。

请尝试使用原地算法完成。你的算法的空间复杂度应为 O(1)，时间复杂度应为 O(nodes)，nodes 为节点总数。

*/

//复杂度都有规定 ，所以就直接操作链表

//。。。做到最后才发现是将奇数节点的节点放外边，还以为是每隔两个节点就插入，，，

//核心代码 
/*
          ListNode*temp = head2->next;
            head1->next = temp;
            head2->next = temp->next;
            head1=temp;
            head2=temp->next;
            
            将奇数的节点就可以挪到前面
*/
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
    ListNode*oddEventList(ListNode*head)
    {
        ListNode*head1 = nullptr;
        ListNode*head2 = nullptr;
        ListNode*ret = nullptr;
        if(head==nullptr||head->next==nullptr||head->next->next==nullptr){
            return head;
        }
        head1=head;
        ListNode*head11 = head1;

        head2= head->next;
        ListNode*head22 = head2;
        while(head1!=nullptr&&head2!=nullptr&&head2->next!=nullptr) 
        {
            ListNode*temp = head2->next;
            head1->next = temp;
            head2->next = temp->next;
            head1=temp;
            head2=temp->next;
        }
        head1->next = head22;
        return head11;
    }
};