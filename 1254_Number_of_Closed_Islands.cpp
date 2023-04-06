/*

Given a 2D grid consists of 0s (land) and 1s (water).  An island is a maximal 4-directionally connected group of 0s and a closed island is an island totally (all left, top, right, bottom) surrounded by 1s.

Return the number of closed islands.

Example 1:

Input: grid = [[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]
Output: 2
Explanation: 
Islands in gray are closed because they are completely surrounded by water (group of 1s).

Example 2:

Input: grid = [[0,0,1,0,0],[0,1,0,1,0],[0,1,1,1,0]]
Output: 1

Example 3:

Input: grid = [[1,1,1,1,1,1,1],
               [1,0,0,0,0,0,1],
               [1,0,1,1,1,0,1],
               [1,0,1,0,1,0,1],
               [1,0,1,1,1,0,1],
               [1,0,0,0,0,0,1],
               [1,1,1,1,1,1,1]]
Output: 2
 

Constraints:

1 <= grid.length, grid[0].length <= 100
0 <= grid[i][j] <=1

*/

/* Solution */

class Solution {
public:
    void dfs_fun(int i,int j,int m,int n,vector<vector<int>>& grid){
        if(!(i>=0 && i<m && j>=0 && j<n && grid[i][j]!=1)){
            return;
        }
        
        grid[i][j]=1;

        dfs_fun(i-1,j,m,n,grid);
        dfs_fun(i+1,j,m,n,grid);
        dfs_fun(i,j-1,m,n,grid);
        dfs_fun(i,j+1,m,n,grid);
    }
    int closedIsland(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        int ans=0;

        //vector<vector<int>> vis(m,vector<int> (n,0));

        for(int i=0;i<n;i++){
            if(grid[0][i]==0){
                dfs_fun(0,i,m,n,grid);
            }
            if(grid[m-1][i]==0){
                dfs_fun(m-1,i,m,n,grid);
            }
        }

        for(int i=0;i<m;i++){
            if(grid[i][0]==0){
                dfs_fun(i,0,m,n,grid);
            }
            if(grid[i][n-1]==0){
                dfs_fun(i,n-1,m,n,grid);
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    dfs_fun(i,j,m,n,grid);
                    ans++;
                }
            }
        }

        return ans;

    }
};
