/*

Given an unsorted integer array nums, return the smallest missing positive integer.

You must implement an algorithm that runs in O(n) time and uses constant extra space.

Example 1:

Input: nums = [1,2,0]
Output: 3

Example 2:

Input: nums = [3,4,-1,1]
Output: 2

Example 3:

Input: nums = [7,8,9,11,12]
Output: 1

Constraints:

1 <= nums.length <= 5 * 105
-231 <= nums[i] <= 231 - 1

*/

/* Solution */

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        // Time Complexity:- O(N)
        // Space Complexity:- O(N)
        
        set<int> s;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0 || nums[i]<0)
            s.insert(nums[i]);
        }
        
        for(int i=1;i<=nums.size();i++){
            if(s.find(i)==s.end()){
                return i;
            }
        }
        return nums.size()+1;
    }
};
