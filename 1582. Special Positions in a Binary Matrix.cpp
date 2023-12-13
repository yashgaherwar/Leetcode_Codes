/*

Given an m x n binary matrix mat, return the number of special positions in mat.

A position (i, j) is called special if mat[i][j] == 1 and all other elements in row i and column j are 0 (rows and columns are 0-indexed).

Example 1:

Input: mat = [[1,0,0],[0,0,1],[1,0,0]]
Output: 1
Explanation: (1, 2) is a special position because mat[1][2] == 1 and all other elements in row 1 and column 2 are 0.
  
Example 2:

Input: mat = [[1,0,0],[0,1,0],[0,0,1]]
Output: 3
Explanation: (0, 0), (1, 1) and (2, 2) are special positions.
 
Constraints:

m == mat.length
n == mat[i].length
1 <= m, n <= 100
mat[i][j] is either 0 or 1.

*/

/* Solution */

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int cnt = 0;
        vector<int> row(mat.size());
        vector<int> col(mat[0].size());

        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j] == 1){
                    row[i]++;
                    col[j]++;
                }
            }
        }

        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j] == 1 && row[i] <= 1 && col[j] <= 1){
                    cnt++;
                }
            }
        }

        return cnt;

    }
};
