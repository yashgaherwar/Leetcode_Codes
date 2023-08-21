/*

Given a string s, check if it can be constructed by taking a substring of it and appending multiple copies of the substring together.

Example 1:

Input: s = "abab"
Output: true
Explanation: It is the substring "ab" twice.

Example 2:

Input: s = "aba"
Output: false

Example 3:

Input: s = "abcabcabcabc"
Output: true
Explanation: It is the substring "abc" four times or the substring "abcabc" twice.
 
Constraints:

1 <= s.length <= 10^4
s consists of lowercase English letters.

*/

/* Solution */

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string k = s;

        for(int i=0;i<s.size()-1;i++){
            char ch1 = k[0];

            k.erase(0,1);
            k.push_back(ch1);

            if(k == s){
                return true;
            }
        }

        return false;

    }
};
