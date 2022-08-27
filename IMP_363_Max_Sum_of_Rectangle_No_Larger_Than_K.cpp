/*

Given an m x n matrix matrix and an integer k, return the max sum of a rectangle in the matrix such that its sum is no larger than k.

It is guaranteed that there will be a rectangle with a sum no larger than k.

Example 1:

Input: matrix = [[1,0,1],[0,-2,3]], k = 2
Output: 2
Explanation: Because the sum of the blue rectangle [[0, 1], [-2, 3]] is 2, and 2 is the max number no larger than k (k = 2).

Example 2:

Input: matrix = [[2,2,-1]], k = 3
Output: 3
 
Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 100
-100 <= matrix[i][j] <= 100
-10^5 <= k <= 10^5

*/

/* Solution */

class Solution {
public:
    // Prefix Sum, Binary Search, Set Approach
    // Time Complexity:- O(n^3logn)
    // Space Complexity:- O(n)
    
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int final_res=INT_MIN;
        int n=matrix.size();
        int m=matrix[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=1;j<m;j++){
                // Prefix Sum Calculated
                matrix[i][j]+=matrix[i][j-1];
            }
        }
        
        // Maintaining the window l-->start and r-->end
        for(int l=0;l<m;l++){
            for(int r=l;r<m;r++){
                set<int> st={0};
                //st.insert(0);
                
                // Prefix sum variable
                int p_sum1=0;
                
                // loop for considering the current width of the rectangle
                for(int i=0;i<n;i++){
                    int sum2=matrix[i][r];
                    if(l>0){
                        sum2=sum2-matrix[i][l-1];
                    }
                    
                    p_sum1=p_sum1 + sum2;
                    
                    int var = p_sum1-k;
                    
                    auto it = st.lower_bound(var);
                    
                    if(it!=st.end()){
                        int tmp=p_sum1-(*it);
                    // updating the final res if it is maximum than the previous one
                        final_res = max(final_res,tmp);
                    }
                    
                    st.insert(p_sum1);
                }
            }
        }
        
        return final_res;
        
    }
};
 
