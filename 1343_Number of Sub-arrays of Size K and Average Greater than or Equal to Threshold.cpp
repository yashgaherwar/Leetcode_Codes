/*

Given an array of integers arr and two integers k and threshold, return the number of sub-arrays of size k and average greater than or equal to threshold.

Example 1:

Input: arr = [2,2,2,2,5,5,5,8], k = 3, threshold = 4
Output: 3
Explanation: Sub-arrays [2,5,5],[5,5,5] and [5,5,8] have averages 4, 5 and 6 respectively. All other sub-arrays of size 3 have averages less than 4 (the threshold).

Example 2:

Input: arr = [11,13,17,23,29,31,7,5,2,3], k = 3, threshold = 5
Output: 6
Explanation: The first 6 sub-arrays of size 3 have averages greater than 5. Note that averages are not integers.
 
Constraints:

1 <= arr.length <= 10^5
1 <= arr[i] <= 10^4
1 <= k <= arr.length
0 <= threshold <= 10^4

*/

/* Solution */

class Solution {
public:

    // Sliding Window Technique
    // Time Complexity:- O(N)
    // Space Complexity:- O(1)
    
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {

        // since ( sum/k >= threshold ) is equivalent to ( sum >= threshold*k )
        // sum/k --> Average
        int target_sum=threshold*k;

        int curr_sum=0;

        // ans for storing total number of valid subarrays
        int ans=0;

        for(int i=0;i<k;i++){
            curr_sum+=arr[i];
        }

        if(curr_sum >= target_sum){
            ans++;
        }

        for(int j=k;j<arr.size();j++){
            curr_sum+=arr[j];
            curr_sum-=arr[j-k];

            if(curr_sum >= target_sum){
                ans++;
            }
        }

        return ans;
        
    }
};
