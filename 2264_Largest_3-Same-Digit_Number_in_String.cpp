/*

You are given a string num representing a large integer. An integer is good if it meets the following conditions:

It is a substring of num with length 3.
It consists of only one unique digit.
Return the maximum good integer as a string or an empty string "" if no such integer exists.

Note:

A substring is a contiguous sequence of characters within a string.
There may be leading zeroes in num or a good integer.
 
Example 1:

Input: num = "6777133339"
Output: "777"
Explanation: There are two distinct good integers: "777" and "333".
"777" is the largest, so we return "777".
  
Example 2:

Input: num = "2300019"
Output: "000"
Explanation: "000" is the only good integer.
  
Example 3:

Input: num = "42352338"
Output: ""
Explanation: No substring of length 3 consists of only one unique digit. Therefore, there are no good integers.
 
Constraints:

3 <= num.length <= 1000
num only consists of digits.

*/

/* Solution */

class Solution {
public:
    string largestGoodInteger(string num) {
        string ans="000";
        int flag=0;
        for(int i=0;i<num.size()-2;i++){
            string res;
            res+=num[i];
            res+=num[i+1];
            res+=num[i+2];
            if(res[0]==res[1] && res[1]==res[2] && res[0]==res[2]){
                if(stoi(res) >= stoi(ans)){
                    ans = res;
                    flag=1;
                }
            }
        }

        if(flag == 0){
            return "";
        }

        return ans;
    }
};
