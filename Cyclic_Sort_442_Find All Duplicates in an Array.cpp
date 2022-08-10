/*

Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears once or twice, return an array of all the integers that appears twice.

You must write an algorithm that runs in O(n) time and uses only constant extra space.

Example 1:

Input: nums = [4,3,2,7,8,2,3,1]
Output: [2,3]

Example 2:

Input: nums = [1,1,2]
Output: [1]

Example 3:

Input: nums = [1]
Output: []

Constraints:

n == nums.length
1 <= n <= 105
1 <= nums[i] <= n
Each element in nums appears once or twice.

*/

/* Solution */

class Solution {
public:
    
    // Cyclic Sort Approach
    // Time Complexity:- O(N)
    // Space Complexity:- O(1)
    
    vector<int> findDuplicates(vector<int>& nums) {
        
        int i=0;
        vector<int> ans;
        
        while(i<nums.size()){
            
            int tmp = nums[i]-1;
            
            if(nums[i]!=nums[tmp]){
                swap(nums[i],nums[tmp]);
            }
            else{
                i++;
            }
        }
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=(i+1)){
                ans.push_back(nums[i]);
            }
        }
        
        
        return ans;
    }
};
