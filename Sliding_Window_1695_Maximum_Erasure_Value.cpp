/*

You are given an array of positive integers nums and want to erase a subarray containing unique elements. The score you get by erasing the subarray is equal to the sum of its elements.
Return the maximum score you can get by erasing exactly one subarray.
An array b is called to be a subarray of a if it forms a contiguous subsequence of a, that is, if it is equal to a[l],a[l+1],...,a[r] for some (l,r).

Example 1:

Input: nums = [4,2,4,5,6]
Output: 17
Explanation: The optimal subarray here is [2,4,5,6].

Example 2:

Input: nums = [5,2,1,2,5,2,1,2,5]
Output: 8
Explanation: The optimal subarray here is [5,2,1] or [1,2,5].
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 104

*/

/* Solution */

class Solution {
public:
    
    // Sliding Window Approach
    // Two Pointers Approach
    
    int maximumUniqueSubarray(vector<int>& nums) {
        
        int n = nums.size();
        
        int l = 0,ans = 0;
        
        vector<int> v(10005);
        
        int curr = 0;
        
        for(int i=0;i<n;i++){
             v[nums[i]] += 1;
             curr += nums[i];
             while(v[nums[i]]>1){
                  v[nums[l]] -= 1;
                  curr -= nums[l];
                  l += 1;
             }
            
             ans = max(ans,curr);
        }
        
        return ans;
        
        
        // Brute Force Approach
        // Time Limit Exceeded 
        /*
        int sum=0;
        unordered_set<int> s;
        int maxi=0;
        for(int i=0;i<nums.size();i++){
            sum=nums[i];
            s.insert(nums[i]);
            
            for(int j=i+1;j<nums.size();j++){
                if(s.find(nums[j])!=s.end()){
                    s.clear();
                    maxi=max(maxi,sum);
                    break;
                }
                
                sum+=nums[j];
                maxi=max(maxi,sum);
                s.insert(nums[j]);
            }
            
            
        }
        int ans=max(maxi,sum);
        return ans;
        */
    }
};
