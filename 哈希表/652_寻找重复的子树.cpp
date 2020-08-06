/*
652. 寻找重复的子树
给定一棵二叉树，返回所有重复的子树。对于同一类的重复子树，你只需要返回其中任意一棵的根结点即可。

两棵树重复是指它们具有相同的结构以及相同的结点值。

示例 1：

        1
       / \
      2   3
     /   / \
    4   2   4
       /
      4
下面是两个重复的子树：

      2
     /
    4
和

    4

*/

#include<vector>
#include<unordered_map>
#include<string>
using namespace std;
//Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

class Solution {
public:
    unordered_map<string,int> hash;
    vector<TreeNode*> ans;
    
    string dfs(TreeNode*u)
    {
        if(!u) return "NULL";
        string left = dfs(u->left);
        string right = dfs(u->right);
        string s = to_string(u->val)+','+left+','+right;
        if(++hash[s]==2) ans.push_back(u);
        return s;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        dfs(root);
        return ans;
    }
};