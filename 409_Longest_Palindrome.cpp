/*

Given a string s which consists of lowercase or uppercase letters, return the length of the longest palindrome that can be built with those letters.

Letters are case sensitive, for example, "Aa" is not considered a palindrome here.

Example 1:

Input: s = "abccccdd"
Output: 7
Explanation: One longest palindrome that can be built is "dccaccd", whose length is 7.

Example 2:

Input: s = "a"
Output: 1
Explanation: The longest palindrome that can be built is "a", whose length is 1.
 
Constraints:

1 <= s.length <= 2000
s consists of lowercase and/or uppercase English letters only.

*/

/* Solution */

class Solution {
public:
    
    // Map Approach
    // Time Complexity:- O(N)
    // Space Complexity:- O(N)
    // Formula Generated:- Summation_of(Even Characters) + Summation_of(Even Characters - 1) + 1(if and only if any odd characters has been occured)
    
    int longestPalindrome(string s) {
        int ans=0;
        unordered_map<char,int> mp;
        int flag=0;
        
        for(auto i: s){
            mp[i]++;
        }
        
        for(auto j: mp){
            if(j.second%2==0){
                ans+=j.second;
            }
            else{
                ans+=(j.second-1);
                flag=1;
            }
        }
        
        if(flag==1){
            return ans+1;
        }
        
        return ans;
        
        
    }
};
