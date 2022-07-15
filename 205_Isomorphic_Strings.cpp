/*

Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

Example 1:

Input: s = "egg", t = "add"
Output: true

Example 2:

Input: s = "foo", t = "bar"
Output: false

Example 3:

Input: s = "paper", t = "title"
Output: true

Constraints:

1 <= s.length <= 5 * 104
t.length == s.length
s and t consist of any valid ascii character.

*/

/* Solution */

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int v1[256]={0};
        int v2[256]={0};
        
        if(s.size()!=t.size()){
            return false;
        }
        
        for(int i=0;i<s.size();i++){
            if(!v1[s[i]] && !v2[t[i]]){
                v1[s[i]]=t[i];
                v2[t[i]]=s[i];
            }
            else{
                if(v1[s[i]]!=t[i]){
                    return false;
                }
            }
        }
        
        return true;
        
    }
};
