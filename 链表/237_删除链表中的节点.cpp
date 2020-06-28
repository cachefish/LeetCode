/*请编写一个函数，使其可以删除某个链表中给定的（非末尾）节点，你将只被给定要求被删除的节点。

*/


//就是删除节点
#include<iostream>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    void deleteNode(ListNode*node)
    {
        if(node==nullptr)
        {
            return;
        }
        if(node->next==nullptr)
        {
            delete node;
            node==nullptr;
        }
        node->val = node->next->val;  //复制
        ListNode*delnode = node->next;
        node->next = delnode->next;  //删除
        delete delnode;
    }
};