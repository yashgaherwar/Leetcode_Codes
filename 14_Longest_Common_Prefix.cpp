/*

Write a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string "".

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"

Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.

Constraints:

1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lowercase English letters.

*/

/* Solution */

class Solution {
public:
    
    // Time Complexity:- O(M*N)
    // Space Complexity:- O(M*N)
    // Can also be done using Trie.
    
    string longestCommonPrefix(vector<string>& strs) {
        
        string ans="";
        
        for(int i=0;i<strs[0].size();i++){
            char ch = strs[0][i];
            int flag=1;
            
            for(int j=1;j<strs.size();j++){
                if(ch!=strs[j][i]){
                    flag=0;
                    break;
                }
            }
            
            if(flag==0){
                break;
            }
            else{
                 ans.push_back(ch);
            }
           
            
        }
        
        return ans;
    }
};
