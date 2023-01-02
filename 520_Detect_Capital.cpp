/*

We define the usage of capitals in a word to be right when one of the following cases holds:

All letters in this word are capitals, like "USA".
All letters in this word are not capitals, like "leetcode".
Only the first letter in this word is capital, like "Google".
Given a string word, return true if the usage of capitals in it is right.

Example 1:

Input: word = "USA"
Output: true

Example 2:

Input: word = "FlaG"
Output: false
 
Constraints:

1 <= word.length <= 100
word consists of lowercase and uppercase English letters.

*/

/* Solution */

class Solution {
public:
    bool detectCapitalUse(string word) {
        int flag1=0,flag2=0,flag3=0;
        for(auto i: word){
            if(i>='a' && i<='z'){
                flag1=1;
            }
            else{
                flag1=0;
                break;
            }
        }

        for(auto i: word){
            if(i>='A' && i<='Z'){
                flag2=1;
            }
            else{
                flag2=0;
                break;
            }
        }

        if(word[0]>='A' && word[0]<='Z'){
            flag3=1;
        }
        for(int i=1;i<word.size();i++){
            if(word[i]>='a' && word[i]<='z'){
                flag3=1;
            }
            else{
                flag3=0;
                break;
            }
        }

        if(flag1==1 || flag2==1 || flag3==1){
            return true;
        }
        else{
            return false;
        }

    }
};
