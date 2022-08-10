/*

Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and uses only constant extra space.

Example 1:

Input: nums = [1,3,4,2,2]
Output: 2

Example 2:

Input: nums = [3,1,3,4,2]
Output: 3

Constraints:

1 <= n <= 105
nums.length == n + 1
1 <= nums[i] <= n
All the integers in nums appear only once except for precisely one integer which appears two or more times.

Follow up:

How can we prove that at least one duplicate number must exist in nums?
Can you solve the problem in linear runtime complexity?

*/

/* Solution */

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
         // Approach 1:- 
         // Cyclic Sort Approach
         // Time Complexity:- O(N)
         // Space Complexity:- O(1)
        
        int i=0;
        while(i<nums.size()){
            int tmp=nums[i]-1;
            
            if(nums[i]!=nums[tmp]){
                swap(nums[i],nums[tmp]);
            }
            else{
                i++;
            }
        }
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=(i+1)){
                return nums[i];
            }
        }
        
        return -1;
    
      
       // Approach 2:- 
       // TC=O(N)
       // SC=O(1)
       // Floyd's Tortoise and Hare Method
        /*
        int slow=nums[0];
        int fast=nums[0];
        
        do{
            slow=nums[slow];
            fast=nums[nums[fast]];
        }while(slow!=fast);
        
        fast=nums[0];
        
        while(slow!=fast){
            slow=nums[slow];
            fast=nums[fast];
        }
        
        return fast;
        */
        
        // Approach 3:- 
        //TC=O(N)
        //SC=O(N)
        /*map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        int flag;
        for(int i=0;i<nums.size();i++){
            if(mp[nums[i]]>1){
                flag=nums[i];
                break;
            }
        }
        
        return flag;*/
        
       
    }
};
