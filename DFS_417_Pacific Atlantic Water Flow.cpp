/*

There is an m x n rectangular island that borders both the Pacific Ocean and Atlantic Ocean. The Pacific Ocean touches the island's left and top edges, and the Atlantic Ocean touches the island's right and bottom edges.

The island is partitioned into a grid of square cells. You are given an m x n integer matrix heights where heights[r][c] represents the height above sea level of the cell at coordinate (r, c).

The island receives a lot of rain, and the rain water can flow to neighboring cells directly north, south, east, and west if the neighboring cell's height is less than or equal to the current cell's height. Water can flow from any cell adjacent to an ocean into the ocean.

Return a 2D list of grid coordinates result where result[i] = [ri, ci] denotes that rain water can flow from cell (ri, ci) to both the Pacific and Atlantic oceans.

 
Example 1:

Input: heights = [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]
Output: [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]
Explanation: The following cells can flow to the Pacific and Atlantic oceans, as shown below:
[0,4]: [0,4] -> Pacific Ocean 
       [0,4] -> Atlantic Ocean
[1,3]: [1,3] -> [0,3] -> Pacific Ocean 
       [1,3] -> [1,4] -> Atlantic Ocean
[1,4]: [1,4] -> [1,3] -> [0,3] -> Pacific Ocean 
       [1,4] -> Atlantic Ocean
[2,2]: [2,2] -> [1,2] -> [0,2] -> Pacific Ocean 
       [2,2] -> [2,3] -> [2,4] -> Atlantic Ocean
[3,0]: [3,0] -> Pacific Ocean 
       [3,0] -> [4,0] -> Atlantic Ocean
[3,1]: [3,1] -> [3,0] -> Pacific Ocean 
       [3,1] -> [4,1] -> Atlantic Ocean
[4,0]: [4,0] -> Pacific Ocean 
       [4,0] -> Atlantic Ocean
Note that there are other possible paths for these cells to flow to the Pacific and Atlantic oceans.
Example 2:

Input: heights = [[1]]
Output: [[0,0]]
Explanation: The water can flow from the only cell to the Pacific and Atlantic oceans.
 
Constraints:

m == heights.length
n == heights[r].length
1 <= m, n <= 200
0 <= heights[r][c] <= 10^5

*/

/* Solution */

class Solution {
public:
    
    // DFS Traversal Approach
    // Time Complexity:- O(m*n)
    // Space Complexity:- O(m*n)
    
    
    // DFS Function implementation
    void dfs_fun(vector<vector<int>> &heights,int i,int j,int prev,vector<vector<int>> &oce){
        if(i<0 || i>=oce.size() || j<0 || j>=oce[0].size()){
            return;
        }
        if(heights[i][j]<prev || oce[i][j]==1){
            return;
        }
        
        oce[i][j]=1;
        
        dfs_fun(heights,i,j+1,heights[i][j],oce);
        dfs_fun(heights,i,j-1,heights[i][j],oce);
        dfs_fun(heights,i+1,j,heights[i][j],oce);
        dfs_fun(heights,i-1,j,heights[i][j],oce);
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        // no. of rows
        int m=heights.size();
        // no. of columns
        int n=heights[0].size();
        
        // 2-d vector for storing ans
        vector<vector<int>> ans;
        
        if(m==0 || n==0){
            return ans;
        }
        
        // pacific and atlantic 2-d vector for checking from which block it is possible to reach the specified location
        vector<vector<int>> pacific(m,vector<int> (n));
        vector<vector<int>> atlantic(m,vector<int> (n));
        
        
        // Depth First Traversal Call
        for(int j=0;j<n;j++){
            dfs_fun(heights,0,j,INT_MIN,pacific);
            dfs_fun(heights,m-1,j,INT_MIN,atlantic);
        }
        
        for(int j=0;j<m;j++){
            dfs_fun(heights,j,0,INT_MIN,pacific);
            dfs_fun(heights,j,n-1,INT_MIN,atlantic);
        }
        
        
        // Intersection of Pacific and Atlantic ocean where both are having true value is our coordinates.
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(pacific[i][j]==1 && atlantic[i][j]==1){
                    ans.push_back({i,j});
                }
            }
        }
        
        return ans;
        
    }
};
