/*

Given two binary strings a and b, return their sum as a binary string.

Example 1:

Input: a = "11", b = "1"
Output: "100"

Example 2:

Input: a = "1010", b = "1011"
Output: "10101"
 
Constraints:

1 <= a.length, b.length <= 10^4
a and b consist only of '0' or '1' characters.
Each string does not contain leading zeros except for the zero itself.

*/

/* Solution */

class Solution {
public:
    string addBinary(string a, string b) {
        int x=a.size()-1;
        int y=b.size()-1;
        int carry=0;
        string res;
        while(x>=0 || y>=0 || carry){
            if(x>=0){
              carry+=(a[x]-'0');
              x--;  
            }
            if(y>=0){
              carry+=(b[y]-'0');
              y--;
            }
            res+=(carry%2+'0');
            carry=carry/2;
        }
        
        reverse(res.begin(),res.end());
        return res;
    }
};
