/*

Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:

Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.

Example 2:

Input: haystack = "leetcode", needle = "leeto"
Output: -1
Explanation: "leeto" did not occur in "leetcode", so we return -1.
 
Constraints:

1 <= haystack.length, needle.length <= 10^4
haystack and needle consist of only lowercase English characters.

*/

/* Solution */

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n=haystack.size();
        int m=needle.size();
        
        if(m>n){
            return -1;
        }
        if(n==m){
            if(haystack==needle) {
                return 0;
            }
            else{
                return -1;
            }
        }
        
        int i=0;
        
        while(i<n){
            int j=0;
            int st=i;
            int count=0;
            
            while(needle[j]==haystack[st] and j<m){
                j++;
                st++;
                count++;
            }
            if(count==m) {
                return i;
            }
            
            i++;
        }
        

        
        return -1;
            
    }
};
