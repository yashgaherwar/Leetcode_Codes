/*

Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

Example 1:

Input: s = "cbaebabacd", p = "abc"
Output: [0,6]
Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".

Example 2:

Input: s = "abab", p = "ab"
Output: [0,1,2]
Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
 
Constraints:

1 <= s.length, p.length <= 3 * 10^4
s and p consist of lowercase English letters.

*/

/* Solution */

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        vector<int> f1(26),f2(26);
        if(p.size() > s.size()){
            return {};
        }
        for(auto i: p){
            f1[i-'a']++;
        }

        int l=0,r=0;

        while(r < s.size()){
            f2[s[r]-'a']++;

            if((r-l+1) < p.size()){
                r++;
            }
            else{
                if(f1==f2){
                    res.push_back(l);
                }
                f2[s[l]-'a']--;
                r++;
                l++;
            }
        }

        return res;

    }
};
