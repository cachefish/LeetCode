/*
给定一个二叉树，返回它的中序 遍历。
*/
#include<iostream>
#include<vector>
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
#if 0
    //递归调用
    vector<int> res;
    vector<int> inorderTraversal(TreeNode* root) {
        if(root){
            inorderTraversal(root->left);
            res.push_back(root->val);
            inorderTraversal(root->right);
        }
        return res;
    }
#endif 
    //中序非递归就是先向左走到头，弹出栈顶元素，向右跳一步，再重复上述步骤
    vector<int> inorderTraversal(TreeNode*root){
        stack<TreeNode*> st;
        vector<int> res;
        TreeNode*p = root;
        while(!st.empty()||p){
            while(p){
                st.push(p);
                p=p->left;
            }
            p=st.top();
            st.pop();
            res.push_back(p->val);
            p=p->right;
        }
        return res;
    }
};