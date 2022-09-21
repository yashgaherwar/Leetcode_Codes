/*

You are given an integer array nums and an array queries where queries[i] = [vali, indexi].

For each query i, first, apply nums[indexi] = nums[indexi] + vali, then print the sum of the even values of nums.

Return an integer array answer where answer[i] is the answer to the ith query.

Example 1:

Input: nums = [1,2,3,4], queries = [[1,0],[-3,1],[-4,0],[2,3]]
Output: [8,6,2,4]
Explanation: At the beginning, the array is [1,2,3,4].
After adding 1 to nums[0], the array is [2,2,3,4], and the sum of even values is 2 + 2 + 4 = 8.
After adding -3 to nums[1], the array is [2,-1,3,4], and the sum of even values is 2 + 4 = 6.
After adding -4 to nums[0], the array is [-2,-1,3,4], and the sum of even values is -2 + 4 = 2.
After adding 2 to nums[3], the array is [-2,-1,3,6], and the sum of even values is -2 + 6 = 4.

Example 2:

Input: nums = [1], queries = [[4,0]]
Output: [0]
 
Constraints:

1 <= nums.length <= 10^4
-104 <= nums[i] <= 10^4
1 <= queries.length <= 10^4
-10^4 <= vali <= 10^4
0 <= indexi < nums.length

*/

/* Solution */

class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        
        // Optimised Approach
        // Time Complexity:- O(N)
        // Space Complexity:- O(N) --> For the Output Vector
        
        int n=nums.size();
        int q=queries.size();
        
        vector<int> ans;
        
        int sum=0;
        
        for(auto itr: nums){
            if(itr%2==0){
                sum+=itr;
            }
        }
        
        
        for(int i=0;i<q;i++){
            
            if(nums[queries[i][1]]%2==0){
                sum-=nums[queries[i][1]];
            }
            
            nums[queries[i][1]]=queries[i][0] + nums[queries[i][1]];
            
            if(nums[queries[i][1]]%2==0){
                sum+=nums[queries[i][1]];
            }
            
            ans.push_back(sum);
        }
        
        return ans;
        
        
        /*
        
        // Brute Force Approach
        
        (TLE) 56/58  --> Test Cases Passed
        
        
        int n=nums.size();
        int q=queries.size();
        
        vector<int> ans;
        
        
        for(int i=0;i<q;i++){
            nums[queries[i][1]]=queries[i][0] + nums[queries[i][1]];
            int sum=0;
            for(auto itr: nums){
                if(itr%2==0){
                    sum+=itr;
                }
            }
            
            ans.push_back(sum);
        }
        
        return ans;
        
        */
    }
};
