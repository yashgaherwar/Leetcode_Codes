/*

Given a string s, reverse only all the vowels in the string and return it.

The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.

Example 1:

Input: s = "hello"
Output: "holle"

Example 2:

Input: s = "leetcode"
Output: "leotcede"
 
Constraints:

1 <= s.length <= 3 * 10^5
s consist of printable ASCII characters.

*/

/* Solution */

class Solution {
public:
    string reverseVowels(string s) {
        
        vector<char> v;
        int j=0;
        
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' || s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U'){
                v.push_back(s[i]);
            }
        }
        
        for(int i=0;i<s.size();i++){
             if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' || s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U'){
                 s[i]=v[j];
                 j++;
             }
        }
        
        return s;
        
      
    }
};
