/*

Given the root of a binary search tree (BST) with duplicates, return all the mode(s) (i.e., the most frequently occurred element) in it.

If the tree has more than one mode, return them in any order.

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than or equal to the node's key.
The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
Both the left and right subtrees must also be binary search trees.
 

Example 1:


Input: root = [1,null,2,2]
Output: [2]
  
Example 2:

Input: root = [0]
Output: [0]
 

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
    map<int,int> mp;

    void solve(TreeNode* root){
        if(root == NULL){
            return;
        }

        mp[root->val]++;
        solve(root->left);
        solve(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        vector<int> ans;
        solve(root);
        
        int maxi = INT_MIN;
        for(auto i: mp){
            maxi=max(maxi, i.second);
        }

        for(auto i: mp){
            if(i.second == maxi){
                ans.push_back(i.first);
            }
        }

        return ans;

    }
};
