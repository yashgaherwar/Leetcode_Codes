/*

Given the root of a binary tree, the level of its root is 1, the level of its children is 2, and so on.

Return the smallest level x such that the sum of all the values of nodes at level x is maximal.

Example 1:

Input: root = [1,7,0,7,-8,null,null]
Output: 2
Explanation: 
Level 1 sum = 1.
Level 2 sum = 7 + 0 = 7.
Level 3 sum = 7 + -8 = -1.
So we return the level with the maximum sum which is level 2.

Example 2:

Input: root = [989,null,10250,98693,-89388,null,null,null,-32127]
Output: 2
 
Constraints:

The number of nodes in the tree is in the range [1, 10^4].
-10^5 <= Node.val <= 10^5

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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int maxi=INT_MIN,level=0,cnt=0;
        
        while(!q.empty()){
            auto sz=q.size();
            vector<int> v;
            int sum=0;
            
            for(int i=0;i<sz;i++){
                TreeNode* ft=q.front();
                q.pop();

                if(ft->left!=NULL){
                    q.push(ft->left);
                    
                }
                if(ft->right!=NULL){
                    q.push(ft->right);
                    
                }
                sum+=ft->val;

            }
            
            cnt++;
             
            if(sum>maxi){
                maxi=sum;
                level=cnt;
            }
            
        }
        return level;
    }
};
