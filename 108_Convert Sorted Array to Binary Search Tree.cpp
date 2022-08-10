/*

Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced binary search tree.

A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.

Example 1:

Input: nums = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: [0,-10,5,null,-3,null,9] is also accepted:

Example 2:

Input: nums = [1,3]
Output: [3,1]
Explanation: [1,null,3] and [3,1] are both height-balanced BSTs.
 
Constraints:

1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums is sorted in a strictly increasing order.

*/

/* Solution */

/*

Recursive Approach.
Binary Search and Divide & Conquer Technique used.

Note:- Divide the Problem into subparts, then solve the subparts and then get to the final solution.

Approach:-

1) As the array is sorted, so the first technique that should come in our mind is Binary Search.
2) Then apply the Binary search by taking two pointers one is left pointer(l) at 0th index and right pointer(r) at last index.
3) Calculate mid and make the element present at that index as a root node.
4) Move the left side of Binary search tree. So update r=mid-1 as all elements in left of Binary search tree are smaller then the root node.
5) Simillary do this for right side and now update l=mid+1.
6) After accessing all the elements return the node which is a Binary Search Tree.

*/

class Solution {
public:

TreeNode* fun(int start,int end,vector<int> &nums){
    if(start>end){                       //Base Condition
        return NULL;
    }
	
    int mid=start+(end-start)/2;         // mid value calculation for Binary search implementation
    TreeNode* node=new TreeNode(nums[mid]);        // creating the node
    node->left=fun(start,mid-1,nums);              // for left subtree
    node->right=fun(mid+1,end,nums);               // for right subtree
    return node;
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
    int start=0;                   // left Pointer (l)
    int end=nums.size()-1;         // Right Pointer (r)
    TreeNode* root=fun(start,end,nums);
    return root;
}
};
