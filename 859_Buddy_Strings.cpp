/*

Given two strings s and goal, return true if you can swap two letters in s so the result is equal to goal, otherwise, return false.

Swapping letters is defined as taking two indices i and j (0-indexed) such that i != j and swapping the characters at s[i] and s[j].

For example, swapping at indices 0 and 2 in "abcd" results in "cbad".

Example 1:

Input: s = "ab", goal = "ba"
Output: true
Explanation: You can swap s[0] = 'a' and s[1] = 'b' to get "ba", which is equal to goal.

Example 2:

Input: s = "ab", goal = "ab"
Output: false
Explanation: The only letters you can swap are s[0] = 'a' and s[1] = 'b', which results in "ba" != goal.

Example 3:

Input: s = "aa", goal = "aa"
Output: true
Explanation: You can swap s[0] = 'a' and s[1] = 'a' to get "aa", which is equal to goal.
 
Constraints:

1 <= s.length, goal.length <= 2 * 10^4
s and goal consist of lowercase letters.

*/

/* Solution */

class Solution {
public:
    bool buddyStrings(string s, string goal) {
        int a=-1,b=-1;
        if(goal.size()!=s.size()){
            return false;
        }

        if(goal==s){
            map<char,int> mp;

            for(int i=0;i<s.size();i++){
                mp[s[i]]++;

                if(mp[s[i]]>1){
                    return true;
                }
            }

            return false;

        }

        for(int i=0;i<s.size();i++){
            if(s[i]!=goal[i]){
                if(a==-1){
                    a=i;
                }
                else if(b==-1){
                    b=i;
                }
                else{
                    return false;
                }
            }
        }

        if(b==-1){
            return false;
        }

        if(s[a]==goal[b] && s[b]==goal[a]){
            return true;
        }

        
        return false;

    }
};
