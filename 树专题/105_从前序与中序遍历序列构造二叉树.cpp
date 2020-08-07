/*
105. 从前序与中序遍历序列构造二叉树
根据一棵树的前序遍历与中序遍历构造二叉树。

注意:
你可以假设树中没有重复的元素。

例如，给出

前序遍历 preorder = [3,9,20,15,7]
中序遍历 inorder = [9,3,15,20,7]
返回如下的二叉树：

    3
   / \
  9  20
    /  \
   15   7
*/
#include<vector>
#include<stack>
#include<unordered_map>
using namespace std;
 // Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Solution {
public:
    unordered_map<int,int> pos;

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        for(int i=0;i<n;i++) pos[inorder[i]] = i;
        return dfs(preorder,inorder,0,n-1,0,n-1);   
    }

    TreeNode*dfs(vector<int>&preorder,vector<int>&inorder,int pl,int pr,int il,int ir)
    {
        if(pl>pr) return NULL;
        int val = preorder[pl];
        int k = pos[preorder[pl]];
        int len = k-il;
        auto root = new TreeNode(val);
        root->left = dfs(preorder,inorder,pl+1,pl+len,il,k-1);
        root->right = dfs(preorder,inorder,pl+len+1,pr,k+1,ir);
        return root;
    }
};