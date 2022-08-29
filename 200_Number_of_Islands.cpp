/*

Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1

Example 2:

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 300
grid[i][j] is '0' or '1'.

*/

/* Solution */

class Solution {
public:
    
    // DFS Approach
  
    void dfs(vector<vector<char>> &grid,int m,int n,int i,int j){
        if(i<0 || i>=m || j<0 || j>=n || grid[i][j]!='1'){
            return;
        }
        
        grid[i][j]='2';
        
        dfs(grid,m,n,i,j-1);
        dfs(grid,m,n,i,j+1);
        dfs(grid,m,n,i-1,j);
        dfs(grid,m,n,i+1,j);
        
    }
    int numIslands(vector<vector<char>>& grid) {
        int count=0;
        int m=grid.size();
        
        if(m==0){
            return 0;
        }
        
        int n=grid[0].size();
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    dfs(grid,m,n,i,j);
                    count++;
                    
                }
            }
        }
        
        return count;
    }
};
