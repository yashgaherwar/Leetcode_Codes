/*
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
Notice that the solution set must not contain duplicate triplets.

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Example 2:

Input: nums = []
Output: []
Example 3:

Input: nums = [0]
Output: []
 
Constraints:

0 <= nums.length <= 3000
-105 <= nums[i] <= 105
*/

/*Solution*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> v;
        int n=nums.size();
        
        if(n<3){
            return v;
        }
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<n-2;i++){
            if(i==0 || (nums[i]!=nums[i-1])){
                int l=i+1,r=n-1;
                while(l<r){
                    int sum=(nums[i]+nums[l]+nums[r]);
                    if(sum==0){
                        v.push_back({nums[i],nums[l],nums[r]});
                        while(l<r && nums[l]==nums[l+1]){
                            l++;
                        }
                        while(l<r && nums[r]==nums[r-1]){
                            r--;
                        }
                        
                        l++;
                        r--;
                    }
                    else if(sum<0){
                        l++;
                    }
                    else{
                        r--;
                    } 
                    
                }
            }
        }
        
        return v;
    }
};
