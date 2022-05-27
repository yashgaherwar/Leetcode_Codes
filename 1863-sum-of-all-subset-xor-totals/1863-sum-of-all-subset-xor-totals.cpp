class Solution {
public:
   
    int subsetXORSum(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> v;
        res.push_back(v);
        funct(0,nums,v,res);
        
        
        int sum=0;
        for(int i=0;i<res.size();i++){
            int ans=0;
            for(int j=0;j<res[i].size();j++){
               ans=ans^res[i][j]; 
            }
            sum+=ans;
            //cout<<sum<<" ";
        }
        
        return sum;
    }
    
    void funct(int j,vector<int> &nums,vector<int> &v,vector<vector<int>> &res){
        for(int i=j;i<nums.size();i++){
            v.push_back(nums[i]);
            res.push_back(v);
            funct(i+1,nums,v,res);
            v.pop_back();
            
        }
    
    
    }
};