/*

Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

A substring is a contiguous sequence of characters within the string.

Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.

Example 2:

Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.

Example 3:

Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.
 

Constraints:

m == s.length
n == t.length
1 <= m, n <= 10^5
s and t consist of uppercase and lowercase English letters.
 

Follow up: Could you find an algorithm that runs in O(m + n) time?

*/

/* Solution */

class Solution {
public:

    // Sliding Window Approach
    // Time Complexity:- O(m+n)
    // Space Complexity:- O(n)
    
    string minWindow(string s, string t) {
        vector<string> ans;
        map<char,int> mp;

        // Storing frequency of each character resent in t string
        for(auto i: t){
            mp[i]++;
        }

        // Starting Point of window
        int i=0;
        // Ending Point of window
        int j=0;
        int count=mp.size();
        // st and mini for storing starting and ending point of our resultant substring
        int st=0;
        int mini=INT_MAX;

        // Actual Approach
        while(j<s.size()){
            mp[s[j]]--;

            if(mp[s[j]]==0){
                count--;
            }

            if(count==0){
                while(count==0){
                   if((j-i+1)<mini){
                       mini=j-i+1;
                       st=i;
                   }

                   mp[s[i]]++;

                   if(mp[s[i]]>0){
                       count++;
                   }

                   i++;
                }
            }
            
            j++;
        }

       
        // If No valid ans possible return empty string else return the final substring 
        if(mini==INT_MAX){
            return "";
        }
        else{
            return s.substr(st,mini);
        }
      
    }
};
