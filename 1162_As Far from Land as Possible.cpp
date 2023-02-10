/*

Given an n x n grid containing only values 0 and 1, where 0 represents water and 1 represents land, find a water cell such that its distance to the nearest land cell is maximized, and return the distance. If no land or water exists in the grid, return -1.

The distance used in this problem is the Manhattan distance: the distance between two cells (x0, y0) and (x1, y1) is |x0 - x1| + |y0 - y1|.


Example 1:

Input: grid = [[1,0,1],[0,0,0],[1,0,1]]
Output: 2
Explanation: The cell (1, 1) is as far as possible from all the land with distance 2.

Example 2:

Input: grid = [[1,0,0],[0,0,0],[0,0,0]]
Output: 4
Explanation: The cell (2, 2) is as far as possible from all the land with distance 4.
 
Constraints:

n == grid.length
n == grid[i].length
1 <= n <= 100
grid[i][j] is 0 or 1

*/

/* Solution */

// BFS Approach

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int ans=0,count=0;
        int m=grid.size();
        int n=grid[0].size();

        vector<int> d1={-1,0,1,0};
        vector<int> d2={0,1,0,-1};

        queue<pair<int,int>> q;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                }
                else{
                    count++;
                }
            }
        }

        if(count==0){
            return -1;
        }

        while(!q.empty()){
            int sz=q.size();
            
            for(int i=0;i<sz;i++){
                auto ft1=q.front();
                int k1=ft1.first;
                int k2=ft1.second;

                q.pop();
            
                for(int j=0;j<4;j++){
                    int l1=k1+d1[j];
                    int l2=k2+d2[j];

                    if(l1>=0 && l1<n && l2>=0 && grid[l1][l2]==0){
                        grid[l1][l2]=1;
                        q.push({l1,l2});
                    }
                }
            }

            ans++;

        }

        return ans-1;
    }
};
