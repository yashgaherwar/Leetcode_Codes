/*

You are given a string s and an array of strings words of the same length. Return all starting indices of substring(s) in s that is a concatenation of each word in words exactly once, in any order, and without any intervening characters.

You can return the answer in any order.

Example 1:

Input: s = "barfoothefoobarman", words = ["foo","bar"]
Output: [0,9]
Explanation: Substrings starting at index 0 and 9 are "barfoo" and "foobar" respectively.
The output order does not matter, returning [9,0] is fine too.

Example 2:

Input: s = "wordgoodgoodgoodbestword", words = ["word","good","best","word"]
Output: []

Example 3:

Input: s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]
Output: [6,9,12]
 

Constraints:

1 <= s.length <= 10000
1 <= words.length <= 5000
1 <= words[i].length <= 30
s and words[i] consist of lowercase English letters.

*/


/* Solution */

class Solution {
public:
    
    // Sliding Window and Map Approach
    
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = words.size();
        int len= words[0].size();
        int tar = n * len;
        
        unordered_map<string,int> mp;
        
        for(int j=0;j<n;j++)
        {
            mp[words[j]]++; 
        }
            vector<int> ans;
        
            if(s.size()<tar)
            {
                return ans;
            }
        
        for(int i=0; i<=s.size()-tar; i++)
        {
            unordered_map<string,int> mp2;
            mp2= mp; 
            
            int k;
            
            for(k=0; k<n; k++)
            {
                    string s1= s.substr(i+k*len,len);
                
                    if(mp2.count(s1)==0){
                        break;
                    }    
                    else if(mp2[s1]!=0){
                        mp2[s1]--;
                    }    
                    else{
                       break; 
                    }
                               
            }

            if(k==n)
            {
                ans.push_back(i);
            }


        }
            return ans;
    }
};
