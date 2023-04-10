/*

Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
 
Example 1:

Input: s = "()"
Output: true

Example 2:

Input: s = "()[]{}"
Output: true

Example 3:

Input: s = "(]"
Output: false
 
Constraints:

1 <= s.length <= 10^4
s consists of parentheses only '()[]{}'.

*/

/* Solution */

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        st.push(s[0]);
        
        for(int i=1;i<s.size();i++){
           if(st.empty()){
               st.push(s[i]);
           } 
           else if(st.top()=='(' && s[i]==')'){
               st.pop();
           }
           else if(st.top()=='{' && s[i]=='}'){
                st.pop();
           }
           else if(st.top()=='[' && s[i]==']'){
                st.pop();
            } 
           else{
                st.push(s[i]);
            }
            
        }
        
        if(st.empty()){
            return true;
        }
        else{
            return false;
        }
        
        
    }
};
