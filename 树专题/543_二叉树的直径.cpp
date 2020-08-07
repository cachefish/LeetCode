/*
543. 二叉树的直径
给定一棵二叉树，你需要计算它的直径长度。一棵二叉树的直径长度是任意两个结点路径长度中的最大值。这条路径可能穿过也可能不穿过根结点。

 

示例 :
给定二叉树

          1
         / \
        2   3
       / \     
      4   5   
*/

#include<vector>
#include<stack>
#include<algorithm>
#include<unordered_map>
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

  class Solution {
public:
    int length = INT_MIN;
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        height(root);
        return length;
    }
    int height(TreeNode*root){
        if(!root) return 0;
        int leftlength = height(root->left);
        int rightlength = height(root->right);
        length = max(length,leftlength+rightlength);
        return 1+max(leftlength,rightlength);
    }
};