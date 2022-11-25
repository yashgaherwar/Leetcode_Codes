/*

Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr. Since the answer may be large, return the answer modulo 109 + 7.

Example 1:

Input: arr = [3,1,2,4]
Output: 17
Explanation: 
Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
Sum is 17.

Example 2:

Input: arr = [11,81,94,43,3]
Output: 444
 
Constraints:

1 <= arr.length <= 3 * 10^4
1 <= arr[i] <= 3 * 10^4

*/

/* Solution */

#define mod 1000000007
#define ll long long

class Solution {
public:

    // Stack Approach

    int sumSubarrayMins(vector<int>& arr) {
        ll ans=0;
        ll n=arr.size();
        stack<ll> st;
        st.push(-1);

        for(ll i=0;i<n+1;i++){
            ll curr;
            if(i<=n-1){
                curr=arr[i];
            }
            else{
                curr=0;
            }

            while(st.top()!=-1 && curr<(arr[st.top()])){
                ll idx=st.top();
                st.pop();
                ll j=st.top();
                ll l=idx-j;
                ll r=i-idx;

                ans+=(r*l*arr[idx])%mod;
                ans=ans%mod;
            }

            st.push(i);
        }

        return ans%mod;
    }
};
