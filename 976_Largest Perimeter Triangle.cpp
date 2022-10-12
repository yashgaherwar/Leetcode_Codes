/*

Given an integer array nums, return the largest perimeter of a triangle with a non-zero area, formed from three of these lengths. If it is impossible to form any triangle of a non-zero area, return 0.

Example 1:

Input: nums = [2,1,2]
Output: 5

Example 2:

Input: nums = [1,2,1]
Output: 0
 
Constraints:

3 <= nums.length <= 10^4
1 <= nums[i] <= 10^6

*/

/* Solution */

class Solution {
public:

    // Time Complexity:- O(n*log(n))
    // Space Complexity:- O(1)
    
    int largestPerimeter(vector<int>& nums) {
        int maxi=0;
        sort(nums.begin(),nums.end(),greater<int>());

        for(int i=0;i<nums.size()-2;i++){
          if(nums[i]<(nums[i+1]+nums[i+2])){
              maxi=max(maxi,(nums[i]+nums[i+1]+nums[i+2]));
          }
        }

        return maxi;
    }
};
