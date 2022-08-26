/*

You are given an integer n. We reorder the digits in any order (including the original order) such that the leading digit is not zero.

Return true if and only if we can do this so that the resulting number is a power of two.

Example 1:

Input: n = 1
Output: true

Example 2:

Input: n = 10
Output: false
 
Constraints:

1 <= n <= 10^9

*/

/* Solution */

class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string num = to_string(n);
        sort(num.begin(),num.end());
        vector<string> res;
        int range = 30;
        
        for(int j=0;j<=range;j++) {
            int kk = pow(2, j);
            res.push_back(to_string(kk)) ;
        }
                        
        for(int j=0;j<=range;j++) {
             sort(res[j].begin(), res[j].end());
         }
                      
        for(int j=0;j<=range;j++){
            if(num==res[j]){
                return true;
            } 
        }
                      
                      
       return false;     
    }
};
