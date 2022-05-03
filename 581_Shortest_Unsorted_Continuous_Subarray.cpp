/*

Given an integer array nums, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order.
Return the shortest such subarray and output its length.

Example 1:

Input: nums = [2,6,4,8,10,9,15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.

Example 2:

Input: nums = [1,2,3,4]
Output: 0

Example 3:

Input: nums = [1]
Output: 0

Constraints:

1 <= nums.length <= 104
-105 <= nums[i] <= 105

Follow up: Can you solve it in O(n) time complexity?

*/

/* Solution */

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        // Time Complexity:- O(NlogN) ----> Due to Sorting
        // Space Complexity:- O(N)
        /*vector<int> v;
        for(int i=0;i<nums.size();i++){
            v.push_back(nums[i]);
        }
        sort(v.begin(),v.end());
        int i=0,j=nums.size()-1;
        for(;i<nums.size();i++){
            if(nums[i]!=v[i]){
               break; 
            }
        }
        
        if(i>=j){
            return 0;
        }
        for(;j>=0;j--){
            if(nums[j]!=v[j]){
               break; 
            }
        }
        
        
        return (j-i+1);*/
        
        // Time Complexity:- O(N) 
        // Space Complexity:- O(1)
        
        int mini=INT_MAX,maxi=INT_MIN;
        
        for(int i=1;i<nums.size();i++){
            if(nums[i]<nums[i-1]){
                mini=min(mini,nums[i]);
            }
        }
        
        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i]>nums[i+1]){
                maxi=max(maxi,nums[i]);
            }
        }
        
        if(mini==INT_MAX && maxi==INT_MIN){
            return 0;
        }
        
        int st=0,ed=nums.size()-1;
        
        for(;st<nums.size();st++){
            if(nums[st]>mini){
                break;
            }
        }
        
        for(;ed>=0;ed--){
            if(nums[ed]<maxi){
                break;
            }
        }
        
        return (ed-st+1);
            
    }
};
