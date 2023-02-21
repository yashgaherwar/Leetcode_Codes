/*

You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

Return the single element that appears only once.

Your solution must run in O(log n) time and O(1) space.

Example 1:

Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2

Example 2:

Input: nums = [3,3,7,7,10,11,11]
Output: 10
 
Constraints:

1 <= nums.length <= 10^5
0 <= nums[i] <= 10^5

*/

/* Solution */

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int i=0,j=nums.size()-1;
        if(nums.size()==1){
            return nums[0];
        }
        if(nums[0]!=nums[1]){
            return nums[0];
        }
        if(nums[j]!=nums[j-1]){
            return nums[j];
        }
        while(i<=j){
            int mid=(i-(i-j)/2);

            if((nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1])){
                return nums[mid];
            }
            else if((nums[mid]==nums[mid-1] && mid%2==0) || (nums[mid]==nums[mid+1] && mid%2!=0)){
                j=mid-1;
            }
            else{
                i=mid+1;
            }
        }

        return nums[i];
    }
};
