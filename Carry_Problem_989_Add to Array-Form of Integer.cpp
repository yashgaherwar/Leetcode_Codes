/*

The array-form of an integer num is an array representing its digits in left to right order.

For example, for num = 1321, the array form is [1,3,2,1].
Given num, the array-form of an integer, and an integer k, return the array-form of the integer num + k.

Example 1:

Input: num = [1,2,0,0], k = 34
Output: [1,2,3,4]
Explanation: 1200 + 34 = 1234

Example 2:

Input: num = [2,7,4], k = 181
Output: [4,5,5]
Explanation: 274 + 181 = 455

Example 3:

Input: num = [2,1,5], k = 806
Output: [1,0,2,1]
Explanation: 215 + 806 = 1021
 
Constraints:

1 <= num.length <= 10^4
0 <= num[i] <= 9
num does not contain any leading zeros except for the zero itself.
1 <= k <= 10^4

*/

/* Solution */

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        string s=to_string(k);
        int sz1=num.size(),sz2=s.size();
        int i=sz1-1,j=sz2-1,crr=0;
        vector<int> ans;

        while(j>=0 || i>=0 || crr){
            int res=0;
            if(i>=0){
                res+=(num[i]);
            }
            if(j>=0){
                res+=(s[j]-'0');
            }

            res+=crr;
            crr=res/10;
            ans.push_back(res%10);
            j--;i--;
        }

        reverse(ans.begin(),ans.end());
        return ans;

    }
};
