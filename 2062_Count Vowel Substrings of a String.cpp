/*  

A substring is a contiguous (non-empty) sequence of characters within a string.

A vowel substring is a substring that only consists of vowels ('a', 'e', 'i', 'o', and 'u') and has all five vowels present in it.

Given a string word, return the number of vowel substrings in word.

Example 1:

Input: word = "aeiouu"
Output: 2
Explanation: The vowel substrings of word are as follows (underlined):
- "aeiouu"
- "aeiouu"

Example 2:

Input: word = "unicornarihan"
Output: 0
Explanation: Not all 5 vowels are present, so there are no vowel substrings.

Example 3:

Input: word = "cuaieuouac"
Output: 7
Explanation: The vowel substrings of word are as follows (underlined):
- "cuaieuouac"
- "cuaieuouac"
- "cuaieuouac"
- "cuaieuouac"
- "cuaieuouac"
- "cuaieuouac"
- "cuaieuouac"

Constraints:

1 <= word.length <= 100
word consists of lowercase English letters only.

*/


/* Solution */

class Solution {
public:
    
    // Map Approach
    // Time Complexity:- O(N*N)
    // Space Complexity:- O(N)
    
    int countVowelSubstrings(string word) {
        
        int count=0;
        map<char,int> mp;
        
        for(int i=0;i<word.size();i++){
            
            for(int j=i;j<word.size();j++){
                if(word[j]=='a' || word[j]=='e' || word[j]=='i' || word[j]=='o' || word[j]=='u'){
                    mp[word[j]]++;
                    if(mp.size()==5) count++;
                }
                else{
                    break;
                }
                
                
            }
            
            mp.clear();
        }
        
        return count;
        
        
    }
};
