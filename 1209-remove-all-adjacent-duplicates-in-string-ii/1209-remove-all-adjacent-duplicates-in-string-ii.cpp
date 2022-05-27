class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char,int>> vp;
        string ans;
        for(auto i: s){
            if(vp.size()==0 || vp.back().first!=i){
                vp.push_back({i,1});
            }
            else{
                vp.back().second++;
            }
            
            if(vp.back().second==k){
                vp.pop_back();
            }
        }
        
        
        for(auto j: vp){
            ans.append(j.second,j.first);
        }
        
        return ans;
    }
};