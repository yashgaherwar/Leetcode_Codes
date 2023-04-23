/*

A program was supposed to print an array of integers. The program forgot to print whitespaces and the array is printed as a string of digits s and all we know is that all integers in the array were in the range [1, k] and there are no leading zeros in the array.

Given the string s and the integer k, return the number of the possible arrays that can be printed as s using the mentioned program. Since the answer may be very large, return it modulo 109 + 7.

Example 1:

Input: s = "1000", k = 10000
Output: 1
Explanation: The only possible array is [1000]

Example 2:

Input: s = "1000", k = 10
Output: 0
Explanation: There cannot be an array that was printed this way and has all integer >= 1 and <= 10.

Example 3:

Input: s = "1317", k = 2000
Output: 8
Explanation: Possible arrays are [1317],[131,7],[13,17],[1,317],[13,1,7],[1,31,7],[1,3,17],[1,3,1,7]
 
Constraints:

1 <= s.length <= 10^5
s consists of only digits and does not contain leading zeros.
1 <= k <= 10^9

*/

/* Solution */

class Solution {
public:
    vector<int> dp;
    int dp_fun(int idx,string &s,int k){
        if(idx==s.size()){
            return 1;
        }

        if(dp[idx]!=-1){
            return dp[idx];
        }

        long long curr_num=0,w=0;

        for(int j=idx;j<s.size();j++){
            long long num=(s[j]-'0')*1LL;
            curr_num=curr_num*10+num;
            if(curr_num>k || curr_num<1){
                break;
            }

            long long ans=dp_fun(j+1,s,k)*1LL;
            w=(w+ans)%(1000000007);
            dp[idx]=w;
        }

        return dp[idx]=(int)w%(1000000007);
    }
    int numberOfArrays(string s, int k) {
        dp.resize(100001,-1);
        return dp_fun(0,s,k);
    }
};
