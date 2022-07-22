/*

You are given a string s consisting only of characters 'a' and 'b'.

You can delete any number of characters in s to make s balanced. s is balanced if there is no pair of indices (i,j) such that i < j and s[i] = 'b' and s[j]= 'a'.

Return the minimum number of deletions needed to make s balanced.

Example 1:

Input: s = "aababbab"
Output: 2
Explanation: You can either:
Delete the characters at 0-indexed positions 2 and 6 ("aababbab" -> "aaabbb"), or
Delete the characters at 0-indexed positions 3 and 6 ("aababbab" -> "aabbbb").

Example 2:

Input: s = "bbaaaaabb"
Output: 2
Explanation: The only solution is to delete the first two characters.
 
Constraints:

1 <= s.length <= 105
s[i] is 'a' or 'b'.

*/

/* Solution */

class Solution {
public:
    
    // Stack Approach
    // Time Complexity:- O(N)
    // Space Complexity:- O(N)
    
    int minimumDeletions(string s) {
        stack<char> st;
        int count=0;
        for(int i=s.size()-1;i>=0;i--){
            if(st.empty() || st.top()!='a'){
                st.push(s[i]);
            }
            else if(st.top()=='a' && s[i]=='b'){
                st.pop();
                count++;
            }
            else{
                st.push(s[i]);
            }
        }
        
        return count;
        
      
      
        /*
        
        // String Approach
        // Time Complexity:- O(N)
        // Space Complexity:- O(1)
        
        
        if(s.size()==1){
            return 0;
        }
        int count_a=count(s.begin(),s.end(),'a');
        int count_b=0;
        int mini=count_a;
        
        for(int i=0;i<s.size();i++){
            
            if(s[i]=='a'){
                count_a--;
            }
            else{
                count_b++;
            }
            
           mini=min(mini,count_a + count_b);
            
        }
        
        return mini;
        
        */
        
        
        
    }
};
