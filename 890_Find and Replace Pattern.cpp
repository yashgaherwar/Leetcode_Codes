/*

Given a list of strings words and a string pattern, return a list of words[i] that match pattern. You may return the answer in any order.

A word matches the pattern if there exists a permutation of letters p so that after replacing every letter x in the pattern with p(x), we get the desired word.

Recall that a permutation of letters is a bijection from letters to letters: every letter maps to another letter, and no two letters map to the same letter.

Example 1:

Input: words = ["abc","deq","mee","aqq","dkd","ccc"], pattern = "abb"
Output: ["mee","aqq"]
Explanation: "mee" matches the pattern because there is a permutation {a -> m, b -> e, ...}. 
"ccc" does not match the pattern because {a -> c, b -> c, ...} is not a permutation, since a and b map to the same letter.

Example 2:

Input: words = ["a","b","c"], pattern = "a"
Output: ["a","b","c"]

Constraints:

1 <= pattern.length <= 20
1 <= words.length <= 50
words[i].length == pattern.length
pattern and words[i] are lowercase English letters.

*/

/* Solution */


class Solution {
public:
    
    // Map Approach
    // Pattern Matching Problem
    
    // Time Complexity:- O(word.size()*pattern.size())
    
    string fun(string pat){
        unordered_map<char,char> mp;
        int ch=97;
        
        for(auto i: pat){
            if(mp[i]==0){
                mp[i]=char(ch);
                ch++;
            }
        }
        
        for(int i=0;i<pat.size();i++){
            pat[i]=mp[pat[i]];
        }
        
        return pat;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        string k = fun(pattern);
        vector<string> ans;
        
        for(auto i: words){
            if(fun(i)==k){
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};
