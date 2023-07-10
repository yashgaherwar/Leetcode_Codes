/*

Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

Note: A leaf is a node with no children.

Example 1:

Input: root = [3,9,20,null,null,15,7]
Output: 2
  
Example 2:

Input: root = [2,null,3,null,4,null,5,null,6]
Output: 5
 
Constraints:

The number of nodes in the tree is in the range [0, 10^5].
-1000 <= Node.val <= 1000

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

    // BFS Approach
    // Time Complexity:- O(N)
    // Space Complexity:- O(N)
     
    int minDepth(TreeNode* root) {
        if(root==NULL){
            return 0;
        }

        queue<TreeNode*> q;
        q.push(root);

        int cnt=0;

        while(!q.empty()){
            int sz=q.size();
            cnt++;

            while(sz--){
                TreeNode* ft=q.front();
                q.pop();
                
                if(ft->left!=NULL){
                    q.push(ft->left);
                }
                if(ft->right!=NULL){
                    q.push(ft->right);
                }

                if(ft->left==NULL and ft->right==NULL){
                    return cnt;
                }
            }
        }

        return cnt;

    }
};
