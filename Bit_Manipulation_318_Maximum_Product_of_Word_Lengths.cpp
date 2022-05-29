/*

Given a string array words, return the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters. If no such two words exist, return 0.

Example 1:

Input: words = ["abcw","baz","foo","bar","xtfn","abcdef"]
Output: 16
Explanation: The two words can be "abcw", "xtfn".

Example 2:

Input: words = ["a","ab","abc","d","cd","bcd","abcd"]
Output: 4
Explanation: The two words can be "ab", "cd".

Example 3:

Input: words = ["a","aa","aaa","aaaa"]
Output: 0
Explanation: No such pair of words.

Constraints:

2 <= words.length <= 1000
1 <= words[i].length <= 1000
words[i] consists only of lowercase English letters.

*/



/* Solution */

class Solution {
public:
    
    // Bit Manipulation Technique Used.
    // Time Complexity:- O(N^2)
    // Space Complexity:- O(N)
    
    int check(string s){
        int ans=0;
        for(int i=0;i<s.size();i++){
            int idx=s[i]-'a';
            ans|=(1<<idx);
            
        }
        
        return ans;
    }
    
    int maxProduct(vector<string>& words) {
        
        vector<int> v(words.size());
        
        for(int i=0;i<words.size();i++){
            v[i]=check(words[i]);
        }
        
        // for(auto i: v){
        //     cout<<i<<" ";
        // }
        cout<<endl;
        int maxi=0;
        for(int i=0;i<words.size();i++){
            for(int j=1;j<words.size();j++){
                if((v[i]&v[j])==0){
                    int a=words[i].size();
                    int b=words[j].size();
                    maxi=max(maxi,a*b);  
                }
                
            }
        }
        
        return maxi;
    }
  
  
  
////////////////////////////////////////////////////////////////        
    // Brute Force Approach
    // Time Limited exceeded
    
    int check(string s1,string s2){
        map<char,int> m;
        for(int i=0;i<s1.size();i++){
            m[s1[i]]++;
        }
        
        for(int i=0;i<s2.size();i++){
            if(m[s2[i]]>0){
                return 1;
            }
        }
        
        return 0;
    }
    int maxProduct(vector<string>& words) {
        
        // sort(words.begin(),words.end(),greater<string>());
        int maxi=0;
        for(int i=0;i<words.size();i++){
            for(int j=1;j<words.size();j++){
                int res=check(words[i],words[j]);
                if(res==0){
                    int a=words[i].size();
                    int b=words[j].size();
                    maxi=max(maxi,a*b);  
                }
            }
        }
        
        return maxi;
    }
    
    
};
