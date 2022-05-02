/*
Given an integer array nums, move all the even integers at the beginning of the array followed by all the odd integers.
Return any array that satisfies this condition.

Example 1:

Input: nums = [3,1,2,4]
Output: [2,4,3,1]
Explanation: The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.
Example 2:

Input: nums = [0]
Output: [0]
 

Constraints:

1 <= nums.length <= 5000
0 <= nums[i] <= 5000

*/

/* Solution */

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> ev,od,ans;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0){
                ev.push_back(nums[i]);
            }
            else{
                od.push_back(nums[i]);
            }
        }
        
        for(int i=0;i<ev.size();i++){
            ans.push_back(ev[i]);
        } 
        for(int i=0;i<od.size();i++){
            ans.push_back(od[i]);
        } 
            
        
        return ans;
    }
};
