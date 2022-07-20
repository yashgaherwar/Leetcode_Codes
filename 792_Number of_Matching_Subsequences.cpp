/*

Given a string s and an array of strings words, return the number of words[i] that is a subsequence of s.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
 
Example 1:

Input: s = "abcde", words = ["a","bb","acd","ace"]
Output: 3
Explanation: There are three strings in words that are a subsequence of s: "a", "acd", "ace".

Example 2:

Input: s = "dsahjpjauf", words = ["ahjpjau","ja","ahbwzgqnuk","tnmlanowax"]
Output: 2
 
Constraints:

1 <= s.length <= 5 * 104
1 <= words.length <= 5000
1 <= words[i].length <= 50
s and words[i] consist of only lowercase English letters.

*/

/* Solution */

class Solution {
public:
  
  // Map + Binary Search Approach 
  // All Test Cases Passed
  
    int fun(string a,string s,unordered_map<char,vector<int>> &mp){
  
        int l=-1;
        
        for(int i=0;a[i]!='\0';i++){
            int p=upper_bound(mp[a[i]].begin(),mp[a[i]].end(),l)-mp[a[i]].begin();
            
            if(p==mp[a[i]].size()){
                return 0;
            }
            
            l=mp[a[i]][p];
        }
        
        return 1;
        
    }
    
    
    
    int numMatchingSubseq(string s, vector<string>& words) {
         int count=0;
         unordered_map<char,vector<int>> mp;
        
         for(int i=0;i<s.size();i++){
            mp[s[i]].push_back(i);
         }
        
        for(int i=0;i<words.size();i++){
            int ans=fun(words[i],s,mp);
            if(ans==1){
                count++;
            }
            
        }
        
        return count;
    }
    

    
    /*
    
    // Stack Approach
    // TLE:- 42/52 cases passed
    
    int fun(string s,string a){
        stack<int> st;
        
        for(int i=0;i<a.size();i++){
            st.push(a[i]);
        }
        
        for(int j=s.size()-1;j>=0;j--){
            if(st.empty()){
                return 1;
            }
            
            if(st.top()==s[j]){
                st.pop();
            }
        }
        
        if(st.empty()){
            return 1;
        }
        else{
            return 0;
        }
    }
    int numMatchingSubseq(string s, vector<string>& words) {
        int count=0;
        for(int i=0;i<words.size();i++){
            int ans=fun(s,words[i]);
            if(ans==1){
                count++;
            }
            
        }
        
        return count;
    }*/
    
};
