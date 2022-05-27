class Solution {
public:
    
    static bool comp(vector<int> &a,vector<int> &b){
        return (a[1]-a[0])>(b[1]-b[0]);
    }
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n=costs.size(),sum=0;
        
        sort(costs.begin(),costs.end(),comp); //Comparator used and it should be static 
        
        for(int i=0;i<n;i++){
            if(i<n/2){
                sum+=costs[i][0];
            }
            else{
                sum+=costs[i][1];
            }
        }
        
        return sum;
    }
};
