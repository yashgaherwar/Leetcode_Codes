/*

You are given an array prices where prices[i] is the price of a given stock on the ith day, and an integer fee representing a transaction fee.

Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

Example 1:

Input: prices = [1,3,2,8,4,9], fee = 2
Output: 8
Explanation: The maximum profit can be achieved by:
- Buying at prices[0] = 1
- Selling at prices[3] = 8
- Buying at prices[4] = 4
- Selling at prices[5] = 9
The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.

Example 2:

Input: prices = [1,3,7,5,10,3], fee = 3
Output: 6
 
Constraints:

1 <= prices.length <= 5 * 10^4
1 <= prices[i] < 5 * 10^4
0 <= fee < 5 * 10^4

*/

/* Solution */

class Solution {
public:
    int dp_fun(vector<int> &prices,int fee,int idx,int buy,vector<vector<int>> &dp){
        if(idx>=prices.size()){
            return 0;
        }

        if(dp[idx][buy]!=-1){
            return dp[idx][buy];
        }

        int ans=0;

        if(buy>0){
            ans = max( -prices[idx] + dp_fun(prices,fee,idx+1,0,dp) , dp_fun(prices,fee,idx+1,1,dp) );
        }
        else{
             ans = max( (prices[idx]-fee) + dp_fun(prices,fee,idx+1,1,dp) , dp_fun(prices,fee,idx+1,0,dp) );
        }

        return dp[idx][buy]=ans;
    }
  
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>> dp(prices.size()+1,vector<int> (2,-1));
        return dp_fun(prices,fee,0,1,dp);
    }
};
