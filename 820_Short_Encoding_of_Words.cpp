/*

A valid encoding of an array of words is any reference string s and array of indices indices such that:
words.length == indices.length
The reference string s ends with the '#' character.
For each index indices[i], the substring of s starting from indices[i] and up to (but not including) the next '#' character is equal to words[i].
Given an array of words, return the length of the shortest reference string s possible of any valid encoding of words.

Example 1:

Input: words = ["time", "me", "bell"]
Output: 10
Explanation: A valid encoding would be s = "time#bell#" and indices = [0, 2, 5].
words[0] = "time", the substring of s starting from indices[0] = 0 to the next '#' is underlined in "time#bell#"
words[1] = "me", the substring of s starting from indices[1] = 2 to the next '#' is underlined in "time#bell#"
words[2] = "bell", the substring of s starting from indices[2] = 5 to the next '#' is underlined in "time#bell#"

Example 2:

Input: words = ["t"]
Output: 2
Explanation: A valid encoding would be s = "t#" and indices = [0].
 

Constraints:

1 <= words.length <= 2000
1 <= words[i].length <= 7
words[i] consists of only lowercase letters.

*/

/* Solution */

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        
        set<string> s1(words.begin(),words.end());
        set<string> s2(words.begin(),words.end());

        int kk = 0;

        for(auto itr: s1){

            for(int i=1;i<itr.size();i++){
                s2.erase(itr.substr(i));
            }
        }

        for(auto itr: s2){
            kk += itr.length() + 1;
        }
        
        
        return kk;
    }
};
