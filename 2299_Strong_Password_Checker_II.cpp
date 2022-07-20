/*

A password is said to be strong if it satisfies all the following criteria:

It has at least 8 characters.
It contains at least one lowercase letter.
It contains at least one uppercase letter.
It contains at least one digit.
It contains at least one special character. The special characters are the characters in the following string: "!@#$%^&*()-+".
It does not contain 2 of the same character in adjacent positions (i.e., "aab" violates this condition, but "aba" does not).
Given a string password, return true if it is a strong password. Otherwise, return false.

Example 1:

Input: password = "IloveLe3tcode!"
Output: true
Explanation: The password meets all the requirements. Therefore, we return true.

Example 2:

Input: password = "Me+You--IsMyDream"
Output: false
Explanation: The password does not contain a digit and also contains 2 of the same character in adjacent positions. Therefore, we return false.

Example 3:

Input: password = "1aB!"
Output: false
Explanation: The password does not meet the length requirement. Therefore, we return false.

Constraints:

1 <= password.length <= 100
password consists of letters, digits, and special characters: "!@#$%^&*()-+".

*/

/* Solution */

class Solution {
public:
    bool strongPasswordCheckerII(string s) {
        if(s.size()<8){
            return false;
        }
        int a=0,b=0,c=0,d=0;
        string str="!@#$%^&*()-+";
        for(int i=0;i<s.size();i++){
            if(i!=0 && s[i]==s[i-1]){
                return false;
            }
            else if(s[i]>='a' && s[i]<='z'){
                a=1;
            }
            else if(s[i]>='A' && s[i]<='Z'){
                b=1;
            }
            else if(s[i]>='0' && s[i]<='9'){
                c=1;
            }
            else if(str.find(s[i])!=string::npos){
                d=1;
            }
            // else if(s[i]=='!' || s[i]=='@' || s[i]=='#' || s[i]=='$' || s[i]=='%' || s[i]=='^' || s[i]=='&' || s[i]=='*' || s[i]=='(' || s[i]==')' || s[i]=='-' || s[i]=='+'){
            //     d=1;
            // }
            
        }
        
        if(a==1 && b==1 && c==1 && d==1){
            return true;
        }
        else{
          return false;  
        }
        
        
    }
};
