/*
257. 二叉树的所有路径
给定一个二叉树，返回所有从根节点到叶子节点的路径。

说明: 叶子节点是指没有子节点的节点。

示例:

输入:

   1
 /   \
2     3
 \
  5

输出: ["1->2->5", "1->3"]

解释: 所有根节点到叶子节点的路径为: 1->2->5, 1->3
*/


#include<vector>
#include<string>
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
    vector<string> ans;
    vector<string> binaryTreePaths(TreeNode* root) {
        string path;
        dfs(root,path);
        return ans;
    }
    void dfs(TreeNode*root,string path){
        if(!root) return;
        if(path.size()) path+="->";
        path+=to_string(root->val);
        if(!root->left&&!root->right){
            ans.push_back(path);
        }else{
            dfs(root->left,path);
            dfs(root->right,path);
        }
    }
};