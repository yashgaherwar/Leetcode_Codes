/*

Given the root of a Binary Search Tree (BST), return the minimum absolute difference between the values of any two different nodes in the tree.

Example 1:

Input: root = [4,2,6,1,3]
Output: 1

Example 2:

Input: root = [1,0,48,null,null,12,49]
Output: 1
 
Constraints:

The number of nodes in the tree is in the range [2, 10^4].
0 <= Node.val <= 10^5

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

    vector<int> v;

    void fun(TreeNode* root){
        if(root==NULL){
            return;
        }

        fun(root->left);
        v.push_back(root->val);
        fun(root->right);
    }
    int getMinimumDifference(TreeNode* root) {
        fun(root);
        int sz=v.size();
        int diff,mini=INT_MAX;
        int i=0,j=sz-1;
        for(int i=1;i<sz;i++){
            diff=v[i]-v[i-1];
            mini=min(mini,diff);
        }

        return mini;
    }
};
 
