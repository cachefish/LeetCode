/*
给定链表头结点 head，该链表上的每个结点都有一个 唯一的整型值 。

同时给定列表 G，该列表是上述链表中整型值的一个子集。

返回列表 G 中组件的个数，这里对组件的定义为：链表中一段最长连续结点的值（该值必须在列表 G 中）构成的集合。
示例 1：

输入: 
head: 0->1->2->3
G = [0, 1, 3]
输出: 2
解释: 
链表中,0 和 1 是相连接的，且 G 中不包含 2，所以 [0, 1] 是 G 的一个组件，同理 [3] 也是一个组件，故返回 2。

*/


//查重

#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
struct ListNode {
      int val;
      ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    int numComponents(ListNode* head, vector<int>& G) {
        unordered_set<int> set(G.begin(),G.end());
        int result = 0;
        while(head){
            //set中存在head节点
            if(set.find(head->val)!=set.end()){
                if(!head->next||set.find(head->next->val)==set.end()){
                    result++;
                }
            }
            head=head->next;
        }
        return result;
    }
    
};