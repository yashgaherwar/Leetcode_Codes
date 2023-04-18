/*

You are given two strings word1 and word2. Merge the strings by adding letters in alternating order, starting with word1. If a string is longer than the other, append the additional letters onto the end of the merged string.

Return the merged string.

Example 1:

Input: word1 = "abc", word2 = "pqr"
Output: "apbqcr"
Explanation: The merged string will be merged as so:
word1:  a   b   c
word2:    p   q   r
merged: a p b q c r

Example 2:

Input: word1 = "ab", word2 = "pqrs"
Output: "apbqrs"
Explanation: Notice that as word2 is longer, "rs" is appended to the end.
word1:  a   b 
word2:    p   q   r   s
merged: a p b q   r   s

Example 3:

Input: word1 = "abcd", word2 = "pq"
Output: "apbqcd"
Explanation: Notice that as word1 is longer, "cd" is appended to the end.
word1:  a   b   c   d
word2:    p   q 
merged: a p b q c   d
 
Constraints:

1 <= word1.length, word2.length <= 100
word1 and word2 consist of lowercase English letters.

*/

/* Solution */

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans;
        int i=0,j=0,k=0;

        while(j<word1.size() && k<word2.size()){
            if(i==0){
                ans+=word1[j];
                j++;
                i=1;
            }
            else{
                ans+=word2[k];
                k++;
                i=0;
            }
            
        }

        if(word1.size()==word2.size()){
            ans+=(word2[word2.size()-1]);
        }
        else if(word1.size()<word2.size()){
            for(int q=k;q<word2.size();q++){
                ans+=word2[q];
            }
        }
        else{
            for(int q=j;q<word1.size();q++){
                ans+=word1[q];
            }
        }

        return ans;       
    }
};
