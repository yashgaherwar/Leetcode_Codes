/*

Given an n x n matrix where each of the rows and columns is sorted in ascending order, return the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.

You must find a solution with a memory complexity better than O(n2).

 

Example 1:

Input: matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8
Output: 13
Explanation: The elements in the matrix are [1,5,9,10,11,12,13,13,15], and the 8th smallest number is 13

Example 2:

Input: matrix = [[-5]], k = 1
Output: -5
 
Constraints:

n == matrix.length == matrix[i].length
1 <= n <= 300
-109 <= matrix[i][j] <= 109
All the rows and columns of matrix are guaranteed to be sorted in non-decreasing order.
1 <= k <= n2
 

Follow up:

Could you solve the problem with a constant memory (i.e., O(1) memory complexity)?
Could you solve the problem in O(n) time complexity? The solution may be too advanced for an interview but you may find reading this paper fun.

*/

/* Solution */


class Solution {
public:
    
    // Binary Search Approach
    // Time Complexity:- O(N*logk)
    // Space Complexity:- O(1)
    
    int check_index(vector<vector<int>>& matrix,int target){
        int n=matrix.size(),tmp=0;
        int i=0,j=n-1;
        
        
        while(i<n && j>=0){
            if(matrix[i][j]>target){
                j--;
            }
            else{
                tmp=tmp+j+1;
                i++;
            }
        }
        
        return tmp;
    }
    
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        int l=matrix[0][0];
        int r=matrix[n-1][n-1];
        
        while(l<r){
            int mid = l+(r-l)/2;
            
            int flag=check_index(matrix,mid);
            if(flag<k){
                l=mid+1;
            }
            else{
                r=mid;
            }
            
        }
        
        return l;
    }
    
    /*
    
    // Brute Force Approach
    // Time Complexity:- O(N*N)
    // Space Complexity:- O(N)
    
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int> v;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                v.push_back(matrix[i][j]);
            }
        }
        
        sort(v.begin(),v.end());
        
        return v[k-1];
    }
    
    */
};
