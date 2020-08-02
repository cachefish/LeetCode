/*
112. 路径总和
给定一个二叉树和一个目标和，判断该树中是否存在根节点到叶子节点的路径，这条路径上所有节点值相加等于目标和。

说明: 叶子节点是指没有子节点的节点。

示例: 
给定如下二叉树，以及目标和 sum = 22，
*/

//
#include<iostream>
#include<queue>
using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root)
        {
            return false;
        }

        queue<TreeNode*> Q;
        queue<int> qsum;

        Q.push(root);
        qsum.push(root->val);
        TreeNode* p;

        while(!Q.empty())
        {
            p = Q.front();
            int res = qsum.front();
            Q.pop();
            qsum.pop();
            if(p->left == NULL&&p->right == NULL)
            {
                if(res == sum) return true;
            }
            if(p->left)
            {
                Q.push(p->left);
                qsum.push(res+p->left->val);
            }
            if(p->right)
            {
                Q.push(p->right);
                qsum.push(res+p->right->val);
            }
        }
        return false;
    }
};