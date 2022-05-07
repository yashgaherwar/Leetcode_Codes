/*
Given an array of n integers nums, a 132 pattern is a subsequence of three integers nums[i], nums[j] and nums[k] such that i < j < k and nums[i] < nums[k] < nums[j].
Return true if there is a 132 pattern in nums, otherwise, return false.

Example 1:

Input: nums = [1,2,3,4]

Output: false
Explanation: There is no 132 pattern in the sequence.

Example 2:

Input: nums = [3,1,4,2]

Output: true
Explanation: There is a 132 pattern in the sequence: [1, 4, 2].

Example 3:

Input: nums = [-1,3,2,0]

Output: true
Explanation: There are three 132 patterns in the sequence: [-1, 3, 2], [-1, 3, 0] and [-1, 2, 0].
 
Constraints:

n == nums.length
1 <= n <= 2 * 105
-109 <= nums[i] <= 109

*/

/* Solution */

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        // Time Complexity = O(N)
        // Space Complexity = O(N)
        stack<int> st;
        int maxi2=INT_MIN;
        for(int i=nums.size()-1;i>=0;i--){
            
            if(nums[i]<maxi2){
                return true;
            }
            
            while(!st.empty() && st.top()<nums[i]){

                int a=st.top();
                st.pop();
                if(a>maxi2){
                    maxi2=a;
                }

                
            }
            
            
            st.push(nums[i]);
            
                
        }
        
        return false;
        
        
        
        
    }
};

/*if(nums[i]>nums[i+1] ){
                if((nums[i-1] < nums[i]) && (nums[i-1]!=nums[i+1]) && (nums[i-1]<nums[i+1]) && (nums[i-1]!=0)){
                    return true;
                }
            }
        }
        // && (nums[i-1]<nums[i+1])
        // && abs(nums[i])!=abs(nums[i+1]) && abs(nums[i])!=abs(nums[i-1]) && abs(nums[i-1])!=abs(nums[i+1])
        // [-2,1,-2]
        return false;
*/        
 /*
        int maxi=*max_element(nums.begin(),nums.end());
        int i=max_element(nums.begin(),nums.end())-nums.begin();
        
        int maxi2=INT_MIN;
        for(int j=i+1;j<nums.size();j++){
            if(nums[j]>maxi2){
                maxi2=nums[j];
            }
        }
        
        
        int mini=INT_MAX;
        for(int j=0;j<i;j++){
            if(nums[j]<mini){
                mini=nums[j];
            }
        }
        
        
        if(maxi>maxi2 && maxi>mini && mini<maxi2){
            return true;
        }
        
        return false;
*/       
