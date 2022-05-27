class Solution {
public:
    // Dynamic Programming
    // Prefix Array Method
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        int m=costs.size();
        
        int sz=days[n-1];
        set<int> s;
        for(auto i: days){
            s.insert(i);
        }
        
        vector<int> dp(sz+1);
        dp[0]=0;
        for(int i=1;i<dp.size();i++){
            int c1=dp[i-1];
            int c2;
            if((i-7)>0){
                c2=dp[i-7];
            }
            else{
                c2=0;
            }
            int c3;
            if((i-30)>0){
                c3=dp[i-30];
            }
            else{
                c3=0;
            }
            
            if(s.find(i)!=s.end()){
                dp[i]=min({c1+costs[0],c2+costs[1],c3+costs[2]});
            }
            else{
                dp[i]=dp[i-1];
            }
        }
        
        return dp[dp.size()-1];
        
        
    }
};