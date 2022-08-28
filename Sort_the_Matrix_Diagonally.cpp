/*

A matrix diagonal is a diagonal line of cells starting from some cell in either the topmost row or leftmost column and going in the bottom-right direction until reaching the matrix's end. For example, the matrix diagonal starting from mat[2][0], where mat is a 6 x 3 matrix, includes cells mat[2][0], mat[3][1], and mat[4][2].

Given an m x n matrix mat of integers, sort each matrix diagonal in ascending order and return the resulting matrix.

Example 1:

Input: mat = [[3,3,1,1],[2,2,1,2],[1,1,1,2]]
Output: [[1,1,1,1],[1,2,2,2],[1,2,3,3]]

Example 2:

Input: mat = [[11,25,66,1,69,7],[23,55,17,45,15,52],[75,31,36,44,58,8],[22,27,33,25,68,4],[84,28,14,11,5,50]]
Output: [[5,17,4,1,52,7],[11,11,25,45,8,69],[14,23,25,44,58,15],[22,27,31,36,50,66],[84,28,75,33,55,68]]
 
Constraints:

m == mat.length
n == mat[i].length
1 <= m, n <= 100
1 <= mat[i][j] <= 100

*/

/* Solution */

class Solution {
public:
    
    // Sorting and Vector Approach
    // Time Complexity:- O((m+n)*k*logk)
    // Space Complexity:- O(k)
    
    void sort_fun(vector<vector<int>>& mat,int m,int n,int r,int c){
        vector<int> v;
        int rw=r;
        int cl=c;
        while(rw<m && cl<n){
            v.push_back(mat[rw][cl]);
            rw++;
            cl++;
        }
        
        sort(v.begin(),v.end());
        int id=0;
        while(r<m && c<n){
            mat[r][c]=v[id];
            id++;
            r++;
            c++;
        }
    }
    
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        
        // Applying sorting row wise
        for(int i=0;i<m;i++){
            sort_fun(mat,m,n,i,0);
        }
        
        // Applying sorting column wise
        for(int i=1;i<n;i++){
            sort_fun(mat,m,n,0,i);
        }
        
        return mat;
    
    }
};
