/*
You are given a 2D array of integers envelopes where envelopes[i] = [wi, hi] represents the width and the height of an envelope.
One envelope can fit into another if and only if both the width and height of one envelope are greater than the other envelope's width and height.
Return the maximum number of envelopes you can Russian doll (i.e., put one inside the other).
Note: You cannot rotate an envelope.
Example 1:
Input: envelopes = [[5,4],[6,4],[6,7],[2,3]]
Output: 3
Explanation: The maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).
Example 2:
Input: envelopes = [[1,1],[1,1],[1,1]]
Output: 1
Constraints:
1 <= envelopes.length <= 105
envelopes[i].length == 2
1 <= wi, hi <= 105
*/

/* Solution */

class Solution {
public:
    
    // Binary Search, Lower Bound Concept and Comparator Concept;
    // O(NlogN) Solution 
    // 87/87 All Test Cases Passed ---->>
    int maxEnvelopes(vector<vector<int>>& envelopes) {
    sort(envelopes.begin(),envelopes.end(),[](const vector<int> &a,const vector<int> &b){
            if(a[0]<b[0]){
                return 1;
            }
            else if(a[0]==b[0]){
                if(a[1]>b[1]){
                    return 1;
                }
                else{
                    return 0;
                }
            }
            return 0;
        });
        int n=envelopes.size();
        vector<int> v;
        v.push_back(envelopes[0][1]);
        int count=1;
        for(int i=1;i<n;i++){
            auto res=lower_bound(v.begin(),v.end(),envelopes[i][1]);
            
            if(res==v.end()){
                count++;
                v.push_back(envelopes[i][1]);
            }
            else{
                (*res)=envelopes[i][1];
            }
        }
        
        return count;
    }
    
    
    
    
    
    /*
    
    Dynamic Programming O(N^2) Solution
    85/87 Test Cases Passed ---->>   
    
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end());
        int n=envelopes.size();
        vector<int> dp(n);
        int flag=0;
        for(int i=0;i<n;i++){
            int maxi=0;
            for(int j=0;j<i;j++){
                if(envelopes[i][1]>envelopes[j][1] && envelopes[i][0]>envelopes[j][0]){
                    if(dp[j]>maxi){
                        maxi=dp[j];
                    }
                }
            }
            
            dp[i]=maxi+1;
            
            if(flag<dp[i]){
                flag=dp[i];
            }
           
        }
        
        return flag;
    }
    
    */
    
};
