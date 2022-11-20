/*

Given a string s representing a valid expression, implement a basic calculator to evaluate it, and return the result of the evaluation.

Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().

Example 1:

Input: s = "1 + 1"
Output: 2

Example 2:

Input: s = " 2-1 + 2 "
Output: 3

Example 3:

Input: s = "(1+(4+5+2)-3)+(6+8)"
Output: 23

Constraints:

1 <= s.length <= 3 * 10^5
s consists of digits, '+', '-', '(', ')', and ' '.
s represents a valid expression.
'+' is not used as a unary operation (i.e., "+1" and "+(2 + 3)" is invalid).
'-' could be used as a unary operation (i.e., "-1" and "-(2 + 3)" is valid).
There will be no two consecutive operators in the input.
Every number and running calculation will fit in a signed 32-bit integer.

*/

/* Solution */

class Solution {
public:
    int calculate(string s) {
        stack<int> st; 
        int res=0; 
        long long curr=0, sign=1; 
       
        
        for(char c : s){ 
                if(isdigit(c)) {
                    curr=10*curr+(c-'0'); 
                }
                else if(c=='+'){
                    res+=curr*sign; 
                    curr=0;
                    sign=1;   
                }
                else if(c=='-'){
                    res+=curr*sign; 
                    curr=0; 
                    sign=-1; 
                }
                else if(c=='('){
                    st.push(res);    
                    st.push(sign); 
                    res=0; 
                    sign=1;
                }
                else if(c==')' ){ 
                    res+=curr*sign; 
                    curr=0;
                    
                    res = res*st.top();
                    st.pop();
                    res=res+st.top();
                    st.pop();
                }
            }

            res+=sign*curr; 

            return res; 
    }
};
