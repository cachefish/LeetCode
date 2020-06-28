/*
给定一个排序链表，删除所有含有重复数字的节点，只保留原始链表中 没有重复出现 的数字。

示例 1:

输入: 1->2->3->3->4->4->5
输出: 1->2->5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

//方法一：因为是有序的，所以可以直接使用map进行记录出现次数，最后创建新链表返回
//方法二：如果一个节点的后n个节点值相等，就将指针移到n节点上，然后让该节点的next等于n节点，就实现去重，使用递归
#include<iostream>
#include<map>
struct ListNode {
    int val;
    ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
};
#if 0
class Solution{
public:
    ListNode*deleteDuplicates(ListNode*head){
        if(!head||!head->next)
        {
            return head;
        }
        std::map<int,int> mp;
        ListNode*cur=head;
        //数据放入map中
        while(cur)
        {
            mp[cur->val]++;
            cur=cur->next;
        }
        cur=head;

        ListNode*dummy = new ListNode(-1);
        ListNode*res = dummy;
        //新链表
        while(cur){
            if(mp[cur->val]==1){
                dummy->next=new ListNode(cur->val);
                dummy=dummy->next;
            }
            cur=cur->next;
        }
        return res->next;
    }
};
#endif

class Solution
{
public:
    ListNode*deleteDuplicates(ListNode*head)
    {
        if(!head){
            return head;
        }
        if(head->next&&head->val==head->next->val){
            while(head->next&&head->val==head->next->val)
            {
                head=head->next;
            }
            return deleteDuplicates(head->next);
        }else
        {
            head->next=deleteDuplicates(head->next);
        }
        return head;
    }
};