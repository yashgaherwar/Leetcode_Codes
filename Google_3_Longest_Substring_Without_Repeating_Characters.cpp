/*

Given a string s, find the length of the longest substring without repeating characters.

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 

Constraints:

0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.

*/

/* Solution */

class Solution {
public:
    
    // Sliding Window Approach using Map
    // Two Pointer Approach
    
    int lengthOfLongestSubstring(string s) {
        map<char,int> mp;
        int i=0,j=0;
        int sz=s.size();
        int maxi=0;
        while(j<sz){
            mp[s[j]]++;
            while(mp[s[j]]!=1){
                mp[s[i]]--;
                i++;
                
            }
            
            maxi=max(maxi,j-i+1);
            j++;
        }
        
        return maxi;
      
        
    }
};
