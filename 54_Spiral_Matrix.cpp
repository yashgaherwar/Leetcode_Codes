/*

Given an m x n matrix, return all elements of the matrix in spiral order.

Example 1:

Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]

Example 2:

Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 10
-100 <= matrix[i][j] <= 100

*/

/* Solution */

class Solution {
public:
    
    // Simulation Approach
    // Time Complexity:- O(m*n)
    // Space Complexity:- O(m*n)
    
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int l=0,r=n-1,x=0,y=m-1;
        int d=0;
        
        vector<int> ans;
        
        if(m==0){
            return ans;
        }
        
        while(l<=r && x<=y){
            if(d==0){
                for(int i=l;i<=r;i++){
                    ans.push_back(matrix[x][i]);
                }
                
                d=1;
                x++;
                
            }
            else if(d==1){
                for(int i=x;i<=y;i++){
                    ans.push_back(matrix[i][r]);
                }
                
                d=2;
                r--;
            }
            else if(d==2){
                for(int i=r;i>=l;i--){
                    ans.push_back(matrix[y][i]);
                }
                
                d=3;
                y--;
                
            }
            else if(d==3){
                for(int i=y;i>=x;i--){
                    ans.push_back(matrix[i][l]);
                }
                
                d=0;
                l++;
            }
        }
        
        return ans;
        
    }
};
