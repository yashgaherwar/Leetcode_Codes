/*

Given an integer array nums and an integer k, return the number of non-empty subarrays that have a sum divisible by k.

A subarray is a contiguous part of an array.

Example 1:

Input: nums = [4,5,0,-2,-3,1], k = 5
Output: 7
Explanation: There are 7 subarrays with a sum divisible by k = 5:
[4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]

Example 2:

Input: nums = [5], k = 9
Output: 0
 
Constraints:

1 <= nums.length <= 3 * 10^4
-10^4 <= nums[i] <= 10^4
2 <= k <= 10^4

*/

/* Solution */

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int curr_sum=0;
        int curr_mod=0;
        int total=0;

        map<int,int> mp;
        mp[curr_mod]++;
        
        for(auto i: nums){
            curr_sum+=i;
            curr_mod=curr_sum%k;

            if(curr_mod<0){
                curr_mod+=k;
            }
            
            if(mp.find(curr_mod)!=mp.end()){
                total=total+(mp[curr_mod]);
                mp[curr_mod]++;
            }
            else{
                mp[curr_mod]++;
            }
        }

        return total;

    }
};
