/*
101. 对称二叉树
给定一个二叉树，检查它是否是镜像对称的。

 

例如，二叉树 [1,2,2,3,4,4,3] 是对称的。

    1
   / \
  2   2
 / \ / \
3  4 4  3
*/
#include<iostream>
#include<stack>
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return dfs(root,root);
    }

    bool dfs(TreeNode*p,TreeNode*q)
    {
        if(!p&&!q){
            return true;
        }
        if(!p||!q){
            return false;
        }
        if(p->val==q->val){
            return dfs(p->left,q->right)&&dfs(p->right,q->left);
        }
        return false;
    }
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        stack<TreeNode*>left,right;
        auto l = root->left,r = root->right;
        while(l||r||left.size()||right.size())
        {
            while(l&&r){
                left.push(l),l=l->left;
                right.push(r),r = r->right;
            }

            if(l||r) return false;

            l = left.top(),left.pop();
            r = right.top(),right.pop();
            if(l->val != r->val) return false;
            
            l = l->right,r=r->left;
        }
        return true;
    }

};