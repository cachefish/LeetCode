/*
给你两个 非空 链表来代表两个非负整数。数字最高位位于链表开始位置。它们的每个节点只存储一位数字。将这两数相加会返回一个新的链表。

你可以假设除了数字 0 之外，这两个数字都不会以零开头。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/add-two-numbers-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

//可以使用两栈操作 都入栈后。top相加后，判断是否有进位，然后进行操作

#include<iostream>
#include<stack>
using std::stack;
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> x;
        stack<int> y;
        //入栈
        while(l1){x.push(l1->val);l1=l1->next;}
        while(l2){y.push(l2->val);l2=l2->next;}
        ListNode*node=nullptr;
        int over = 0;
        while(!x.empty()||!y.empty()||over>0){
            int sum_=over;
            //相加
            if(!x.empty()){sum_+=x.top();x.pop();}
            if(!y.empty()){sum_+=y.top();y.pop();}

            ListNode*temp = new ListNode(sum_%10);
            temp->next = node;
            node=temp;
            over=sum_/10;  //进位
        }
        return node; 
    }
};