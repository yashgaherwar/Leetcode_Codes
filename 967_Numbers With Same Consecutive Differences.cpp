/*

Return all non-negative integers of length n such that the absolute difference between every two consecutive digits is k.

Note that every number in the answer must not have leading zeros. For example, 01 has one leading zero and is invalid.

You may return the answer in any order.

Example 1:

Input: n = 3, k = 7
Output: [181,292,707,818,929]
Explanation: Note that 070 is not a valid number, because it has leading zeroes.

Example 2:

Input: n = 2, k = 1
Output: [10,12,21,23,32,34,43,45,54,56,65,67,76,78,87,89,98]
 
Constraints:

2 <= n <= 9
0 <= k <= 9

*/

/* Solution */

class Solution {
public:
    
    // Recursion and Backtracking Approach
    
    void dfs_fun(int n,int k,int curr,int curr_len,int prev, vector<int> &ans){
        if(curr_len==n-1){
            ans.push_back(curr);
            return;
        }
        
        int next=prev+k;
        
        if(next<10){
            dfs_fun(n,k,curr*10+next,curr_len+1,next,ans);
        }
        
        next=prev-k;
        if(next>=0 && k!=0){
            dfs_fun(n,k,curr*10+next,curr_len+1,next,ans);
        }
        
    }
    
    
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> ans;
        
        if(n==1){
            for(int i=0;i<=9;i++){
                ans.push_back(i);
            }
            return ans;
        }
        
        for(int i=1;i<=9;i++){
            dfs_fun(n,k,i,0,i,ans);
        }
        
        return ans;
    }
};
