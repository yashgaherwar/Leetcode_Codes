/*

The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);
 
Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"

Example 2:

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:
P     I    N
A   L S  I G
Y A   H R
P     I

Example 3:

Input: s = "A", numRows = 1
Output: "A"
 
Constraints:

1 <= s.length <= 1000
s consists of English letters (lower-case and upper-case), ',' and '.'.
1 <= numRows <= 1000

*/

/* Solution */

class Solution {
public:
    string convert(string s, int numRows) {
        int n=s.size(),i=0;
        vector<string> ans(n,"");
        string res;

        while(i<n){
            for(int j=0;j<numRows && i<n;j++){
                ans[j].push_back(s[i]);
                i++;
            }

            for(int j=numRows-2;j>=1 && i<n;j--){
                ans[j].push_back(s[i]);
                i++;
            }
        }

        for(auto itr: ans){
            res+=itr;
        }

        return res;

    }
};
