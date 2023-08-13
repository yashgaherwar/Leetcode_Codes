/*

You are given a 0-indexed integer array nums. You have to partition the array into one or more contiguous subarrays.

We call a partition of the array valid if each of the obtained subarrays satisfies one of the following conditions:

The subarray consists of exactly 2 equal elements. For example, the subarray [2,2] is good.
The subarray consists of exactly 3 equal elements. For example, the subarray [4,4,4] is good.
The subarray consists of exactly 3 consecutive increasing elements, that is, the difference between adjacent elements is 1. For example, the subarray [3,4,5] is good, but the subarray [1,3,5] is not.
Return true if the array has at least one valid partition. Otherwise, return false.

Example 1:

Input: nums = [4,4,4,5,6]
Output: true
Explanation: The array can be partitioned into the subarrays [4,4] and [4,5,6].
This partition is valid, so we return true.
  
Example 2:

Input: nums = [1,1,1,2]
Output: false
Explanation: There is no valid partition for this array.
 
Constraints:

2 <= nums.length <= 10^5
1 <= nums[i] <= 10^6

*/

/* Solution */

class Solution {
public:
    bool dp_fun(vector<int> &nums,int idx,vector<int> &dp){

        int n = nums.size();

        if(idx>=n){
            return true;
        }

        if(dp[idx]!=-1){
            return dp[idx];
        }

        if((idx+1)<n && nums[idx]==nums[idx+1]){
            if(dp_fun(nums,idx+2,dp)){
                return dp[idx]=true;
            }
        }

        if((idx+2)<n && (idx+1)<n && nums[idx]==nums[idx+1] && nums[idx+1]==nums[idx+2]){
            if(dp_fun(nums,idx+3,dp)){
                return dp[idx]=true;
            }
        }

        if((idx+2)<n && (idx+1)<n && nums[idx]==nums[idx+1]-1 && nums[idx+1]==nums[idx+2]-1){
            if(dp_fun(nums,idx+3,dp)){
                return dp[idx]=true;
            }
        }

        return dp[idx] = false;

    }

    bool validPartition(vector<int>& nums) {
        vector<int> dp(nums.size()+1,-1);
       
        return dp_fun(nums,0,dp);
    }
};
