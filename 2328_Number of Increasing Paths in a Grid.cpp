/*

You are given an m x n integer matrix grid, where you can move from a cell to any adjacent cell in all 4 directions.

Return the number of strictly increasing paths in the grid such that you can start from any cell and end at any cell. Since the answer may be very large, return it modulo 109 + 7.

Two paths are considered different if they do not have exactly the same sequence of visited cells.

Example 1:

Input: grid = [[1,1],[3,4]]
Output: 8
Explanation: The strictly increasing paths are:
- Paths with length 1: [1], [1], [3], [4].
- Paths with length 2: [1 -> 3], [1 -> 4], [3 -> 4].
- Paths with length 3: [1 -> 3 -> 4].
The total number of paths is 4 + 3 + 1 = 8.

Example 2:

Input: grid = [[1],[2]]
Output: 3
Explanation: The strictly increasing paths are:
- Paths with length 1: [1], [2].
- Paths with length 2: [1 -> 2].
The total number of paths is 2 + 1 = 3.
 
Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 1000
1 <= m * n <= 10^5
1 <= grid[i][j] <= 10^5

*/

/* Solution */

class Solution {
public:
    int mod=(1000000007);
    int dfs_fun(int i,int j,vector<vector<int>> &grid,int parent,vector<vector<int>> &dp){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || parent>=grid[i][j]){
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int left = dfs_fun(i,j-1,grid,grid[i][j],dp);
        int right = dfs_fun(i,j+1,grid,grid[i][j],dp);
        int up = dfs_fun(i-1,j,grid,grid[i][j],dp);
        int down = dfs_fun(i+1,j,grid,grid[i][j],dp);

        return dp[i][j] = (1 + left + right + up + down)%(1000000007);


    }
    int countPaths(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans=0;
        vector<vector<int>> dp(m+1,vector<int> (n+1,-1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                
                ans=(ans + dfs_fun(i,j,grid,-1,dp))%(1000000007);
                
            }
        }

        return ans;

    }
};
