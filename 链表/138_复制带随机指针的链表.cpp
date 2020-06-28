/*
给定一个链表，每个节点包含一个额外增加的随机指针，该指针可以指向链表中的任何节点或空节点。

要求返回这个链表的 深拷贝。 

我们用一个由 n 个节点组成的链表来表示输入/输出中的链表。每个节点用一个 [val, random_index] 表示：

val：一个表示 Node.val 的整数。
random_index：随机指针指向的节点索引（范围从 0 到 n-1）；如果不指向任何节点，则为  null 。
 

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/copy-list-with-random-pointer
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/  

//使用map存放random和random所指的位置
#include<iostream>
#include<map>
#include<vector>
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
public:
    Node*copyRandomList(Node*head)
    {
        std::map<Node*,int> mp;
        std::vector<Node*> nlist;
        int i =0;
        Node*ptr = head;
        //创建新链表并mp做记录
        while(ptr)
        {
            nlist.push_back(new Node(ptr->val));
            mp[ptr] = i;
            i++;
            ptr=ptr->next;
        }
        i=0;
        ptr = head;
        nlist.push_back(nullptr);
        while(ptr){
            nlist[i]->next = nlist[i+1];
            if(ptr->random){
                int id = mp[ptr->random];
                nlist[i]->random=nlist[id];
            }
            i++;
            ptr=ptr->next;
        }
        return nlist[0];
    }


};
