/*

Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.

Example 1:

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]

Example 2:

Input: nums = [2,0,1]
Output: [0,1,2]
 
Constraints:

n == nums.length
1 <= n <= 300
nums[i] is either 0, 1, or 2.

*/

/* Solution */

class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int n0=0,n1=0,n2=0;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                n0++;
            }
            else if(nums[i]==1){
                n1++;
            }
            else{
                n2++;
            }
        }
        
        for(int i=0;i<n0;i++){
            nums[i]=0;
        }
        for(int i=0;i<n1;i++){
            nums[n0+i]=1;
        }
        for(int i=0;i<n2;i++){
            nums[n0+n1+i]=2;
        }
        
      
      
        /*
        // Bubble Sort Approach
        
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[j]<nums[i]){
                    swap(nums[i],nums[j]);
                }
            }
        }
        */
    }
};
 
