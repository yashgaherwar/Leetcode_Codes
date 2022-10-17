/*

A pangram is a sentence where every letter of the English alphabet appears at least once.

Given a string sentence containing only lowercase English letters, return true if sentence is a pangram, or false otherwise.

 

Example 1:

Input: sentence = "thequickbrownfoxjumpsoverthelazydog"
Output: true
Explanation: sentence contains at least one of every letter of the English alphabet.

Example 2:

Input: sentence = "leetcode"
Output: false
 
Constraints:

1 <= sentence.length <= 1000
sentence consists of lowercase English letters.

*/

/* Solution */

class Solution {
public:
    bool checkIfPangram(string sentence) {
        map<char,int> mp;

        for(auto i: sentence){
            mp[i]++;
        }

        for(char j='a';j<='z';j++){
            if(mp[j]<1){
                return false;
            }
        }

        return true;
    }

};
