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
    int deepestLeavesSum(TreeNode* root) {
        vector<vector<int>> v;
        
        if(root==NULL){
            return 0;
        }
        int sum;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            int sz=q.size();
            
            vector<int> res;
            sum=0;
            for(int i=0;i<sz;i++){
                TreeNode* node=q.front();
                q.pop();
                sum+=node->val;
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
                
                res.push_back(node->val);
            }
            
            v.push_back(res);
            
        }
        
        /*int sum=0;
        for(int i=0;i<v[v.size()-1].size();i++){
            sum+=v[v.size()-1][i];
        }*/
        
        return sum;
    }
};