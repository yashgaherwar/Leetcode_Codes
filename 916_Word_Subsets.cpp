/*

You are given two string arrays words1 and words2.

A string b is a subset of string a if every letter in b occurs in a including multiplicity.

For example, "wrr" is a subset of "warrior" but is not a subset of "world".
A string a from words1 is universal if for every string b in words2, b is a subset of a.

Return an array of all the universal strings in words1. You may return the answer in any order.

Example 1:

Input: words1 = ["amazon","apple","facebook","google","leetcode"], words2 = ["e","o"]
Output: ["facebook","google","leetcode"]

Example 2:

Input: words1 = ["amazon","apple","facebook","google","leetcode"], words2 = ["l","e"]
Output: ["apple","google","leetcode"]

Constraints:

1 <= words1.length, words2.length <= 104
1 <= words1[i].length, words2[i].length <= 10
words1[i] and words2[i] consist only of lowercase English letters.
All the strings of words1 are unique.

*/

/* Solution */

class Solution {
public:
  
    // Map Approach
  
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
         //map<char,int> mp1;
        vector<int> mp1(26,0);
        
        vector<string> res;
        
        for(int i=0;i<words2.size();i++){
            string ch=words2[i];
            //map<char,int> mp2;
            vector<int> mp2(26,0);
            
            for(auto j: ch){
                mp2[j-'a']++;
                
                mp1[j-'a']=max(mp1[j-'a'],mp2[j-'a']);
            }
            
        }
        
        for(int i=0;i<words1.size();i++){
            //map<char,int> mp3;
            vector<int> mp3(26,0);
            int temp=1;
            
            for(auto j: words1[i]){
                mp3[j-'a']++;
            }
            
            for(int k=0;k<26;k++){
                if(mp1[k]>mp3[k]){
                    temp=0;
                    break;
                }
            }
            
            if(temp==1){
                res.push_back(words1[i]);
            }
        }
        
        return res;
    }
};
