/*

You are given an array nums consisting of positive integers.

We call a subarray of nums nice if the bitwise AND of every pair of elements that are in different positions in the subarray is equal to 0.

Return the length of the longest nice subarray.

A subarray is a contiguous part of an array.

Note that subarrays of length 1 are always considered nice.

Example 1:

Input: nums = [1,3,8,48,10]
Output: 3
Explanation: The longest nice subarray is [3,8,48]. This subarray satisfies the conditions:
- 3 AND 8 = 0.
- 3 AND 48 = 0.
- 8 AND 48 = 0.
It can be proven that no longer nice subarray can be obtained, so we return 3.

Example 2:

Input: nums = [3,1,5,11,13]
Output: 1
Explanation: The length of the longest nice subarray is 1. Any subarray of length 1 can be chosen.
 
Constraints:

1 <= nums.length <= 10^5
1 <= nums[i] <= 10^9

*/

/* Solution */

class Solution {
public:
   
    int longestNiceSubarray(vector<int>& nums) {
        vector<int> b(31,0);
        int k=0;
        int maxi=0;
        
        for(int i=0;i<nums.size();i++){
            int tmp=0;
            
            for(int j=0;j<31;j++){
               if(nums[i] & (1<<j)){
                   b[j]++;
                   if(b[j]>1){
                       tmp=1;
                   }
                    
               } 
            }
            
            if(tmp==0){
                maxi=max(maxi,i-k+1);
            }
            else{
                while(k<=i){
                    for(int j=0;j<31;j++){
                        if(nums[k] & (1<<j)){
                            b[j]--;
                        }
                    }
                    
                    k=k+1;
                    
                    int tmp=0;
                    
                    for(int j=0;j<31;j++){
                        if(b[j]>1){
                            tmp=1;
                        }
                    }
                    
                    if(tmp==0){
                        break;
                    }
                }
            }
            
        }
        
        
        return maxi;
        
    }
};


 
   
