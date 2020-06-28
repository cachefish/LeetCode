/*
给定一个链表，判断链表中是否有环。

为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/linked-list-cycle
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

//可以使用快慢指针，一个走一步，一个走两步，有环必定相遇

#include<iostream>
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head||!head->next) return false;
        auto p(head),q(head);
        while(q->next){
            p=p->next;
            q=q->next->next;
            if(!q) return false;
            if(p==q) return true;
        }
        return false;
    }
};