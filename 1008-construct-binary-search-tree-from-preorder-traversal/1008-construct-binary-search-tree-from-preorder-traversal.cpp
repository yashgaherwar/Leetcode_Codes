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
     /*TreeNode* my_fun(vector<int> &preorder,int i,int j){
        
         if(i>j){
             return NULL;
         }
         int mid=i+(j-i)/2;
         
         TreeNode* node=new TreeNode(preorder[mid]);
         
         node->left=my_fun(preorder,i,mid-1);
         node->right=my_fun(preorder,mid+1,j);
         
         return node;
     }
    
    
     TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        int i=0,j=preorder.size()-1;
        sort(preorder.begin(),preorder.end());
        return my_fun(preorder,i,j);
    }*/
    
    
    TreeNode* fun(vector<int> &preorder,int &i,int j){
        if(i==preorder.size() || preorder[i]>j){
            return NULL;
        }
        
        TreeNode* node=new TreeNode(preorder[i]);
        i++;
        node->left=fun(preorder,i,node->val);
        node->right=fun(preorder,i,j);
        
        return node;
        
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return fun(preorder,i,INT_MAX);
    }
    
};