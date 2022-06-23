/*

Given two strings s and t, return true if they are equal when both are typed into empty text editors. '#' means a backspace character.
Note that after backspacing an empty text, the text will continue empty.

Example 1:

Input: s = "ab#c", t = "ad#c"
Output: true
Explanation: Both s and t become "ac".

Example 2:

Input: s = "ab##", t = "c#d#"
Output: true
Explanation: Both s and t become "".

Example 3:

Input: s = "a#c", t = "b"
Output: false
Explanation: s becomes "c" while t becomes "b".
 

Constraints:

1 <= s.length, t.length <= 200
s and t only contain lowercase letters and '#' characters.
 
Follow up: Can you solve it in O(n) time and O(1) space?

*/

/* Solution 2 */

class Solution {
public:
    
    // Approach 1: Using String.
    // Approach 2: Can also be solved using Stack;
    
    bool backspaceCompare(string s, string t) {
        string s_new,t_new;
        int cc=0,ct=0;
        
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='#'){
                cc++;
            }
            else{
                if(cc==0){
                    s_new+=s[i];
                }
                else if(cc>0){
                    cc--;
                }
            }
        }
        
        
        
        for(int i=t.size()-1;i>=0;i--){
            if(t[i]=='#'){
                ct++;
            }
            else{
                if(ct==0){
                    t_new+=t[i];
                }
                else{
                    ct--;
                }
            }
        }
        
        //cout<<t_new<<endl;
        
        if(s_new==t_new){
            return true;
        }
        else{
            return false;
        }
        
        
        
        
        
    }
};
