/*
98. 验证二叉搜索树
给定一个二叉树，判断其是否是一个有效的二叉搜索树。

假设一个二叉搜索树具有如下特征：

节点的左子树只包含小于当前节点的数。
节点的右子树只包含大于当前节点的数。
所有左子树和右子树自身必须也是二叉搜索树。
示例 1:

输入:
    2
   / \
  1   3
输出: true
*/
#include<iostream>
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
  class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return dfs(root,INT_MIN,INT_MAX);
    }
    bool dfs(TreeNode*root,long long minv,long long maxv)
    {
        if(!root) return true;
        if(root->val<minv||root->val>maxv) return false;
        return dfs(root->left,minv,root->val-1ll)&&
                dfs(root->right,root->val+1ll,maxv);
    }

};