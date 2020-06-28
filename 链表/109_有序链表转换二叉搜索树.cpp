/*
给定一个单链表，其中的元素按升序排序，将其转换为高度平衡的二叉搜索树。

本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。
示例:

给定的有序链表： [-10, -3, 0, 5, 9],

一个可能的答案是：[0, -3, 9, -10, null, 5], 它可以表示下面这个高度平衡二叉搜索树：

      0
     / \
   -3   9
   /   /
 -10  5

*/

/*
如果当前head为null，返回null；否则使用快慢指针找到中间节点。
为中间节点的值创建树节点，并以中间节点将原链表分割成两部分。
递归处理两个子问题，将其返回作为根的左右子树
*/
#include<iostream>
#include<vector>
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};


struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution
{
public:
    TreeNode*sortListToBST(ListNode*head)
    {
        std::vector<int> v;
        while(head!=nullptr){
            v.push_back(head->val);
            head=head->next;
        }
        return buildTree(v,0,v.size());
    }
    TreeNode*buildTree(std::vector<int>&v,int begin,int end){
        if(begin==end) return nullptr;
        int middle = (begin+end)/2;
        TreeNode*root = new TreeNode(v[middle]);
        root->left = buildTree(v,begin,middle);
        root->right = buildTree(v,middle+1,end);
        return root;
    }
};