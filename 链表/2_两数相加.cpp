/*
给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/add-two-numbers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/
//思路：两个节点相加，有进位就记录，再下个节点相加时加上进位，没有进位就直接入链

#include<iostream>
struct ListNode{
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};
class Solution
{
public:
    ListNode*addTwoNumbers(ListNode*L1,ListNode*L2)
    {
        int sum = 0;  //用于记录两节点加后得值
        ListNode*p1 = L1;
        ListNode*p2 = L2;
        ListNode *newList = new ListNode(0); //新链表
        ListNode *p = newList;
        while(p1!=nullptr||p2!=nullptr||sum>0)
        {
            if(p1!=nullptr){
                sum+=p1->val;    //2   4
                p1=p1->next;
            }
            if(p2!=nullptr){
                sum+=p2->val;    //5   6 
                p2=p2->next;
            }
            p->val = sum%10;  //7  0
            sum/=10;    //判断是否有进位   0  1
            if(p1!=nullptr||p2!=nullptr||sum>0){
                p->next = new ListNode(0);
                p=p->next;
            } 
        }
        return newList;
    }
};
//这个解法更精简
int c=0;
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    if(l1==NULL && l2==NULL && c==0)return NULL;
    l1 = l1!=NULL ? (c += l1->val, l1->next) : l1;
    l2 = l2!=NULL ? (c += l2->val, l2->next) : l2;
    struct ListNode *cur = (struct ListNode *)malloc(sizeof(struct ListNode));
    cur->val = c%10;
    c /= 10;
    cur->next = addTwoNumbers(l1,l2);
    return cur;
}
