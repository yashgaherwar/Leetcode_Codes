class Solution {
public:
    // 1) Analyse the pattern:
    // n==1 (1 1 1 1 1)
    // n==2 (5 4 3 2 1)
    // n==3 (15 10 6 3 1)
    
    // 2) Then apply Dynamic Programming
    
     int countVowelStrings(int n) {
        vector<int> dp(5,1);
        int res=0;
        n=n-1;
        while(n--){
            for(int i=dp.size()-2;i>=0;i--){
                dp[i]+=(dp[i+1]);
            }
        }
        
        for(auto it: dp){
            res+=it;
        }
        
        return res;
    }
};