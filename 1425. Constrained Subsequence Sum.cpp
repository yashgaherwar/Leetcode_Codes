/*

Given an integer array nums and an integer k, return the maximum sum of a non-empty subsequence of that array such that for every two consecutive integers in the subsequence, nums[i] and nums[j], where i < j, the condition j - i <= k is satisfied.

A subsequence of an array is obtained by deleting some number of elements (can be zero) from the array, leaving the remaining elements in their original order.

Example 1:

Input: nums = [10,2,-10,5,20], k = 2
Output: 37
Explanation: The subsequence is [10, 2, 5, 20].
  
Example 2:

Input: nums = [-1,-2,-3], k = 1
Output: -1
Explanation: The subsequence must be non-empty, so we choose the largest number.
  
Example 3:

Input: nums = [10,-2,-10,-5,20], k = 2
Output: 23
Explanation: The subsequence is [10, -2, -5, 20].
 
Constraints:

1 <= k <= nums.length <= 100000
-10000 <= nums[i] <= 10000

*/

/* Solution */

class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();

        priority_queue<pair<int, int>> pq;
        pq.push({nums[0],0});

        int maxi = nums[0];

        for(int i=1;i<n;i++){
            int idx = pq.top().second;
            if((i-idx) > k){
                while(!pq.empty() && (i- pq.top().second) > k){
                    pq.pop();
                }

                if(pq.size() == 0){
                    pq.push({nums[i],i});
                    maxi = max(maxi, nums[i]);
                }
                else{
                    int sum = nums[i] + pq.top().first;
                    int maxi2 = max(sum, nums[i]);
                    
                    maxi = max(maxi, maxi2);
                    pq.push({maxi2,i});
                }
            }
            else{
                int sum = nums[i] + pq.top().first;
                int maxi2 = max(sum, nums[i]);
                
                maxi = max(maxi, maxi2);
                pq.push({maxi2,i});
            }
            
        }

        return maxi;
    }
};
