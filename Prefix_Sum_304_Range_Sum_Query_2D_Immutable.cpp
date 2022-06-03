/*

Given a 2D matrix matrix, handle multiple queries of the following type:
Calculate the sum of the elements of matrix inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).
Implement the NumMatrix class:
NumMatrix(int[][] matrix) Initializes the object with the integer matrix matrix.
int sumRegion(int row1, int col1, int row2, int col2) Returns the sum of the elements of matrix inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).
 
Example 1:

Input
["NumMatrix", "sumRegion", "sumRegion", "sumRegion"]
[[[[3, 0, 1, 4, 2], [5, 6, 3, 2, 1], [1, 2, 0, 1, 5], [4, 1, 0, 1, 7], [1, 0, 3, 0, 5]]], [2, 1, 4, 3], [1, 1, 2, 2], [1, 2, 2, 4]]

Output
[null, 8, 11, 12]

Explanation
NumMatrix numMatrix = new NumMatrix([[3, 0, 1, 4, 2], [5, 6, 3, 2, 1], [1, 2, 0, 1, 5], [4, 1, 0, 1, 7], [1, 0, 3, 0, 5]]);
numMatrix.sumRegion(2, 1, 4, 3); // return 8 (i.e sum of the red rectangle)
numMatrix.sumRegion(1, 1, 2, 2); // return 11 (i.e sum of the green rectangle)
numMatrix.sumRegion(1, 2, 2, 4); // return 12 (i.e sum of the blue rectangle)
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 200
-105 <= matrix[i][j] <= 105
0 <= row1 <= row2 < m
0 <= col1 <= col2 < n
At most 104 calls will be made to sumRegion.

*/

/* Solution */

class NumMatrix {
public:
    
    // Prefix Sum Approach
    // Time Complexity in Constructor:- O(N*M)
    // Time Complexity Per Query:- O(1)
    // Space Complexity:- O(N*M)
    
    vector<vector<int>> matrix;
    NumMatrix(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        
        for(int i=0;i<m;i++){
            for(int j=1;j<n;j++){
                matrix[i][j]+=(matrix[i][j-1]);
            }
        }
        
         for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){
                matrix[i][j]+=(matrix[i-1][j]);
            }
        }
        
        this->matrix=matrix;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans1=matrix[row2][col2];
        int x1,x2,x3;
        if(col1!=0){
            x1=matrix[row2][col1-1];
        }
        else{
            x1=0;
        }
        if(row1!=0){
            x2=matrix[row1-1][col2];
        }
        else{
            x2=0;
        }
        if(row1!=0 && col1!=0){
            x3=matrix[row1-1][col1-1];
        }
        else{
            x3=0;
        }
        
        //int ans2=matrix[row2][col1-1]+matrix[row1-1][col2]-matrix[row1-1][col1-1];
        int ans2=x1+x2-x3;
        int ans3=ans1-ans2;
        return ans3;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
