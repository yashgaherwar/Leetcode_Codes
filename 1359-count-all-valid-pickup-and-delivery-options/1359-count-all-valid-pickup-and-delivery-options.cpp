class Solution {
public:
    int countOrders(int n) {
        vector<int> dp(n);
        dp[0]=1;
        
        for(int i=1;i<n;i++){
            long long w=i*2+1;
            long long tmp=(w*w - (w*(w-1))/2);
            dp[i]=(dp[i-1]*tmp)%1000000007;         
                     
        }
                           
        return dp[n-1];
    }
};