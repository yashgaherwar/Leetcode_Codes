/*

Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.

Example 1:

Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").

Example 2:

Input: s1 = "ab", s2 = "eidboaoo"
Output: false
 
Constraints:

1 <= s1.length, s2.length <= 10^4
s1 and s2 consist of lowercase English letters.

*/

/* Solution */

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        if(s1.size()>s2.size()){
            return false;
        }
        
        unordered_map<char,int> m;
        
        for(int i=0;i<s1.size();i++){
            m[s1[i]]++;
        }
        
        int k=s1.size();
        int i=0,j=0;
        int count=m.size();
        
        while(j<s2.size()){
            
            
            if(m.find(s2[j])!=m.end()){
                m[s2[j]]--;
                if(m[s2[j]]==0){
                    count--;
                }
            }
            
            if(j-i+1<k){
                j++;
            }
            else if(j-i+1==k){
                
                
                if(count==0){
                    return true;
                }
            
                if(m.find(s2[i])!=m.end()){
                    m[s2[i]]++;
                    if(m[s2[i]]==1){
                        count++;
                    }
                }

                i++;
                j++;
            }
            
            
        }
        
        return false;
        
    }
};
