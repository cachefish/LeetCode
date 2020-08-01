/*
剑指 Offer 07. 重建二叉树
输入某二叉树的前序遍历和中序遍历的结果，请重建该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。

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

 // Definition for a binary tree node.

#include<map>
#include<vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Solution {
public:
    map<int,int> hash;
    vector<int> preorder,inorder;
    TreeNode* buildTree(vector<int>& _preorder, vector<int>& _inorder) {
        preorder = _preorder,inorder=_inorder;
        for(int i =0;i<inorder.size();i++)  hash[inorder[i]]=i;
        return dfs(0,preorder.size()-1,0,inorder.size()-1);
    }
    TreeNode*dfs(int pl,int pr,int il,int ir)
    {
        if(pl>pr) return nullptr;
        auto root = new TreeNode(preorder[pl]);
        int k = hash[root->val];
        auto left = dfs(pl+1,pl+k-il,il,k-1);
        auto right = dfs(pl+k-il+1,pr,k+1,ir);
        root->left=left,root->right=right;
        return root;
    }
};

class Solution {
public:
    TreeNode*dfs(vector<int>&pre,int preStart,int preEnd,vector<int>&vin,int vinStart,int vinEnd){
        if(preStart>preEnd||vinStart>vinEnd){
            return NULL;
        }
        TreeNode*root = new TreeNode(pre[preStart]);
        for(auto i = vinStart;i<=vinEnd;i++){//在中序序列中找根节点        
        if(pre[preStart]==vin[i]){
            root->left = dfs(pre,preStart+1,i-vinStart+preStart,vin,vinStart,i-1);
            root->right = dfs(pre,i-vinStart+preStart+1,preEnd,vin,i+1,vinEnd);
            break;
            }
        }
    return root;
    }

    TreeNode* buildTree(vector<int>& pre, vector<int>& vin) {
        if(pre.empty()||vin.empty())
        {
            return NULL;
        }
        return dfs(pre,0,pre.size()-1,vin,0,vin.size()-1);
    }
};