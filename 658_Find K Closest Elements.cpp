/*

Given a sorted integer array arr, two integers k and x, return the k closest integers to x in the array. The result should also be sorted in ascending order.

An integer a is closer to x than an integer b if:

|a - x| < |b - x|, or
|a - x| == |b - x| and a < b
 
Example 1:

Input: arr = [1,2,3,4,5], k = 4, x = 3
Output: [1,2,3,4]

Example 2:

Input: arr = [1,2,3,4,5], k = 4, x = -1
Output: [1,2,3,4]
 
Constraints:

1 <= k <= arr.length
1 <= arr.length <= 10^4
arr is sorted in ascending order.
-10^4 <= arr[i], x <= 10^4

*/

/* Solution */


// Two Pointer Approach
// Time Complexity:- O(N)
// Space Complexity:- O(N)

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int i=0;
        int j=arr.size()-1;
        vector<int> ans;
        if(arr.size()==1){
            return {arr[0]};
        }
        while((j-i)>=k){
            int m=abs(arr[i]-x);
            int n=abs(x-arr[j]);
            
            
            if(m<=n){
               j--; 
            }
            else{
                i++;
            }
  
        }
        
        
        for(int m=i;m<=j;m++){
            ans.push_back(arr[m]);
        }
        
        return ans;
    }
};
