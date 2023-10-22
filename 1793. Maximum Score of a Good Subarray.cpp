/*

You are given an array of integers nums (0-indexed) and an integer k.
The score of a subarray (i, j) is defined as min(nums[i], nums[i+1], ..., nums[j]) * (j - i + 1). A good subarray is a subarray where i <= k <= j.
Return the maximum possible score of a good subarray.

Example 1:

Input: nums = [1,4,3,7,4,5], k = 3
Output: 15
Explanation: The optimal subarray is (1, 5) with a score of min(4,3,7,4,5) * (5-1+1) = 3 * 5 = 15.
  
Example 2:

Input: nums = [5,5,4,5,4,1,1,1], k = 0
Output: 20
Explanation: The optimal subarray is (0, 4) with a score of min(5,5,4,5,4) * (4-0+1) = 4 * 5 = 20.
 
Constraints:

1 <= nums.length <= 100000
1 <= nums[i] <= 2 * 10000
0 <= k < nums.length

*/

/* Solution */

class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int mini = nums[k];
        int res = nums[k];
        int i=k-1, j=k+1;

        for(int p=2;p<=nums.size();p++){
            int mini1;
            int mini2;
            if(i>=0){
                mini1 = min(mini, nums[i]);
            }
            else{
                mini1 = min(mini, 0);

            }

            if(j<nums.size()){
                mini2 = min(mini, nums[j]);
            }
            else{
                mini2 = min(mini, 0);
            }

            if(mini2 <= mini1){
                i--;
            }
            else{
                j++;
            }

            mini = max(mini1, mini2);
            res = max(res, p*mini);
        }

        return res;

    }
};
