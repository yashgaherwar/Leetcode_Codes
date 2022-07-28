/*

You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

Return the length of the longest substring containing the same letter you can get after performing the above operations.

Example 1:

Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.

Example 2:

Input: s = "AABABBA", k = 1
Output: 4
Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.

Constraints:

1 <= s.length <= 105
s consists of only uppercase English letters.
0 <= k <= s.length

*/

// Solution 

class Solution {
public:

// Sliding Window and Map Approach
// Time Complexity:- O(N)
// Space Complexity:- O(N)

int characterReplacement(string s, int k) {
    int maxFreq=0;    // For storing max frequency character
    int st=0;         // Starting point of sliding window
    int maxi=0;       // For storing max length subarray
    map<char,int> mp; // Map for maintaing frequency of each character
    
    for(int i=0;i<s.size();i++){
        mp[s[i]]++;
        
        maxFreq=max(maxFreq,mp[s[i]]);
        
        if(((i-st+1)-maxFreq)>k){
            mp[s[st]]--;  
            
            st++;
        }
        
        maxi=max(maxi,i-st+1);
    }
    
    return maxi;
}
};
