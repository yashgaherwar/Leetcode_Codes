/*

You are given an array of n strings strs, all of the same length.

The strings can be arranged such that there is one on each line, making a grid. For example, strs = ["abc", "bce", "cae"] can be arranged as:

abc
bce
cae
You want to delete the columns that are not sorted lexicographically. In the above example (0-indexed), columns 0 ('a', 'b', 'c') and 2 ('c', 'e', 'e') are sorted while column 1 ('b', 'c', 'a') is not, so you would delete column 1.

Return the number of columns that you will delete.

Example 1:

Input: strs = ["cba","daf","ghi"]
Output: 1
Explanation: The grid looks as follows:
  cba
  daf
  ghi
Columns 0 and 2 are sorted, but column 1 is not, so you only need to delete 1 column.


Example 2:

Input: strs = ["a","b"]
Output: 0
Explanation: The grid looks as follows:
  a
  b
Column 0 is the only column and is sorted, so you will not delete any columns.


Example 3:

Input: strs = ["zyx","wvu","tsr"]
Output: 3
Explanation: The grid looks as follows:
  zyx
  wvu
  tsr
All 3 columns are not sorted, so you will delete all 3.
 

Constraints:

n == strs.length
1 <= n <= 100
1 <= strs[i].length <= 1000
strs[i] consists of lowercase English letters.

*/

/* Solution */

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int m=strs.size();
        int n=strs[0].size();
        vector<vector<char>> v(m,vector<char> (n,0));
        
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
             //v.push_back(strs[i][j]);
                v[i][j]=strs[i][j];
            }
        }
        
        int j=0;
        int count=0;
        
        for(int i=0;i<n;i++) {
            vector<char> u, p;
           
            while(j<m) {
                u.push_back(v[j][i]);
                j++;
            }
            
            p=u;
            
            sort(p.begin(),p.end());
            
            if(u!=p) {
                count++;
            }
            
            j=0;
            
        }
        
        return count;
    }
};
