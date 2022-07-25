/*

Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]

Example 3:

Input: nums = [], target = 0
Output: [-1,-1]
 

Constraints:

0 <= nums.length <= 105
-109 <= nums[i] <= 109
nums is a non-decreasing array.
-109 <= target <= 109

*/

/* Solution */

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        // Binary Search Approach
        // Time Complexity:- O(logN)
        // Space Complexity:- O(logN)
        
        
        int l=0,r=nums.size()-1;
        int res1=-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            
            if(nums[mid]==target){
                res1=mid;
                r=mid-1;
            }
            else if(nums[mid]<target){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        
        l=0;
        r=nums.size()-1;
        int res2=-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            
            if(nums[mid]==target){
                res2=mid;
                l=mid+1;
            }
            else if(nums[mid]<target){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        
        return {res1,res2};
        
        

        /*
        
        // Time Complexity:- O(N)
        // Space Complexity:- O(N)
        
        vector<int> v;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target){
                v.push_back(i);
                break;
            }
        }
        
        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i]==target){
                v.push_back(i);
                break;
            }
        }
        
        if(v.size()==0){
            return {-1,-1};
        }
        else{
          return v;  
        }
    
        */
        
    }
};
