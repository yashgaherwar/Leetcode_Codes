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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL){
            return ans;;  
        }
        
        unordered_map<int,vector<int>> m;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        int mini=0,maxi=0;
        
        while(!q.empty()){
            
            int n=q.size();
            multiset<pair<int,int>> s;
            
            while(n--){
                TreeNode* root=q.front().first;
                int dist=q.front().second;
                //auto [root,dist]=q.front();
                q.pop();
                s.insert({root->val,dist});
                
                mini=min(mini,dist);
                maxi=max(maxi,dist);
                
                //m[dist].push_back(root->val);

                if(root->left!=NULL){
                    q.push({root->left,dist-1});
                }
                if(root->right!=NULL){
                    q.push({root->right,dist+1});
                } 
            }   
            
            for(auto& [val,x]: s){
                m[x].push_back(val);
            }
            
        }
        
        
        
        
        for(int i=mini;i<=maxi;i++){
            
            ans.push_back(m[i]);
           /* vector<int> res;
            if(m.find(mini)!=m.end()){
                for(auto i: m[mini]){
                    res.push_back(i);
                }
                
            }
            //sort(res.begin(),res.end());
            ans.push_back(res);
            mini++;*/
        }
        
        return ans;
        
        
        
        
        
    }
};