/*

There is a one-dimensional garden on the x-axis. The garden starts at the point 0 and ends at the point n. (i.e The length of the garden is n).

There are n + 1 taps located at points [0, 1, ..., n] in the garden.

Given an integer n and an integer array ranges of length n + 1 where ranges[i] (0-indexed) means the i-th tap can water the area [i - ranges[i], i + ranges[i]] if it was open.

Return the minimum number of taps that should be open to water the whole garden, If the garden cannot be watered return -1.

Example 1:

Input: n = 5, ranges = [3,4,1,1,0,0]
Output: 1
Explanation: The tap at point 0 can cover the interval [-3,3]
The tap at point 1 can cover the interval [-3,5]
The tap at point 2 can cover the interval [1,3]
The tap at point 3 can cover the interval [2,4]
The tap at point 4 can cover the interval [4,4]
The tap at point 5 can cover the interval [5,5]
Opening Only the second tap will water the whole garden [0,5]

Example 2:

Input: n = 3, ranges = [0,0,0,0]
Output: -1
Explanation: Even if you activate all the four taps you cannot water the whole garden.
  
Constraints:

1 <= n <= 10^4
ranges.length == n + 1
0 <= ranges[i] <= 100

*/

/* Solution */

class Solution {
public:
    long long dp_fun(int idx,vector<pair<int,int>> &vp,int k,vector<int> &dp){
        if(vp[idx].second == k){
            return 1;
        }

        if(dp[idx] != -1){
            return dp[idx];
        }

        if(idx == vp.size()){
            return INT_MAX;
        }

        long long mini = INT_MAX;

        for(int j=idx+1;j<vp.size();j++){
            if(vp[idx].second < vp[j].first){
                break;
            }

            mini = min(mini, 1+dp_fun(j,vp,k,dp));
        }

        return dp[idx] = mini;
    }
    int minTaps(int n, vector<int>& ranges) {
        vector<int> dp(n+1,-1);
        vector<pair<int,int>> vp;

        for(int i=0;i<ranges.size();i++){
            int a = max(0,i-ranges[i]);
            int b = min(i+ranges[i],n);
            vp.push_back({a,b});
        }

        sort(vp.begin(),vp.end());

        long long res = INT_MAX;

        for(int i=0;i<vp.size();i++){
            if(vp[i].first == 0){
                res = min(res, dp_fun(i,vp,n,dp));
            }
        }

        if(res == INT_MAX){
            return -1;
        }

        return res;




    }
};
