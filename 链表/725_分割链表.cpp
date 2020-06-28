/*
给定一个头结点为 root 的链表, 编写一个函数以将链表分隔为 k 个连续的部分。

每部分的长度应该尽可能的相等: 任意两部分的长度差距不能超过 1，也就是说可能有些部分为 null。

这k个部分应该按照在链表中出现的顺序进行输出，并且排在前面的部分的长度应该大于或等于后面的长度。

返回一个符合上述规则的链表的列表。
举例： 1->2->3->4, k = 5 // 5 结果 [ [1], [2], [3], [4], null ]
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/split-linked-list-in-parts
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

//先求出链表的长度，然后判断可分为几段链表

#include<iostream>
#include<vector>
using std::vector;
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
     vector<ListNode*> splitListToParts(ListNode* root, int k) {
        ListNode*temp =root;
        int length = 0;
        while(temp){
            temp=temp->next;
            length++;
        }
        int avelength = length/k;  //分为几段
        int remainder = length%k;   //余下的节点，均匀分配给其他链表
        vector<ListNode*>result(k,NULL);
        ListNode*head = root;
        ListNode*pre = nullptr;
        for(int i =0;i<k;i++){
            result[i]=head;
            int templength = remainder>0?(avelength+1):avelength;
            for(int j=0;j<templength;j++){
                pre=head;
                head=head->next;
            }
            if(pre) pre->next=nullptr;
            if(remainder!=0) remainder--;
        }
        return result;
    }
};