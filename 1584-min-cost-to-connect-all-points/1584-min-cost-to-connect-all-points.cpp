class Solution {
public:
    
    // Using Prims Algorithm:-
    // It can also be done bby Kruskals Algoritms
    
    
    int fun(vector<int>& parents, int idx){
        
        if(parents[idx]==idx){
            return idx;
        }
        
        parents[idx] = fun(parents, parents[parents[idx]]);
        
        return parents[idx];
        
        
    }
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        
        int n = points.size();
        vector<int> parents(n);        
        iota(parents.begin(), parents.end(), 0);
        int ans = 0;
        int edges = 0;
        priority_queue<vector<int>> pq;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(i!=j){
                     pq.push({-1*(abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1])), i, j});
                }
            }
        }
        
        
        while(edges!=n-1){
            
            vector<int> edge = pq.top();
            
            int p1 = fun(parents, edge[1]);
            int p2 = fun(parents, edge[2]);
            
            if(p1!=p2){
                
                ans += -1*edge[0];
                
                parents[p1] = p2;
                
                edges++;
                
                
            }
            
            pq.pop();
            
        }
        
        
        
        return ans;
        
        
    }
};