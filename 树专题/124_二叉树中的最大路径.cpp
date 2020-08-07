/*
124. 二叉树中的最大路径和
给定一个非空二叉树，返回其最大路径和。

本题中，路径被定义为一条从树中任意节点出发
，达到任意节点的序列。该路径至少包含一个节点，且不一定经过根节点。
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
    int maxv = -11111111;
    int maxPathSum(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        calc(root);
        return maxv;
    }
    int calc(TreeNode*node){
        if(node==NULL){
            return 0;
        }
        int temp = node->val;
        int lmaxsum = calc(node->left);
        int rmaxsum = calc(node->right);

        if(lmaxsum>0)
            temp +=lmaxsum;
        if(rmaxsum>0)
            temp+=rmaxsum;
        if(temp>maxv)
            maxv=temp;

        return max(node->val,max(node->val+lmaxsum,node->val+rmaxsum)); 
    }

};