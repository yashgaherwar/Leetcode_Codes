/*

Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.

Example 1:

Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
Output: [3,9,20,null,null,15,7]

Example 2:

Input: inorder = [-1], postorder = [-1]
Output: [-1]

Constraints:

1 <= inorder.length <= 3000
postorder.length == inorder.length
-3000 <= inorder[i], postorder[i] <= 3000
inorder and postorder consist of unique values.
Each value of postorder also appears in inorder.
inorder is guaranteed to be the inorder traversal of the tree.
postorder is guaranteed to be the postorder traversal of the tree.

*/

/* Solution */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* fun(vector<int>& inorder,int i,int in,vector<int>& postorder,int j,int post,map<int,int>& mp){
       if(i>in || j>post){
           return NULL;
       } 
        
        TreeNode* root = new TreeNode(postorder[post]);
        
        int a = mp[postorder[post]];
        int b = a-i;
        
        root->left = fun(inorder,i,a-1,postorder,j,j+b-1,mp);
        
        root->right = fun(inorder,a+1,in,postorder,j+b,post-1,mp);
        
        return root;
    }
    
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int> mp;
        
        int in=inorder.size();
        int post=postorder.size();
        
        for(int i=0;i<post;i++){
            mp[inorder[i]]=i;
        }
        
        return fun(inorder,0,in-1,postorder,0,post-1,mp);
    }
};
