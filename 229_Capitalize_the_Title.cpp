/*

You are given a string title consisting of one or more words separated by a single space, where each word consists of English letters. Capitalize the string by changing the capitalization of each word such that:

If the length of the word is 1 or 2 letters, change all letters to lowercase.
Otherwise, change the first letter to uppercase and the remaining letters to lowercase.
Return the capitalized title.

Example 1:

Input: title = "capiTalIze tHe titLe"
Output: "Capitalize The Title"
Explanation:
Since all the words have a length of at least 3, the first letter of each word is uppercase, and the remaining letters are lowercase.

Example 2:

Input: title = "First leTTeR of EACH Word"
Output: "First Letter of Each Word"
Explanation:
The word "of" has length 2, so it is all lowercase.
The remaining words have a length of at least 3, so the first letter of each remaining word is uppercase, and the remaining letters are lowercase.

Example 3:

Input: title = "i lOve leetcode"
Output: "i Love Leetcode"
Explanation:
The word "i" has length 1, so it is lowercase.
The remaining words have a length of at least 3, so the first letter of each remaining word is uppercase, and the remaining letters are lowercase.
 
Constraints:

1 <= title.length <= 100
title consists of words separated by a single space without any leading or trailing spaces.
Each word consists of uppercase and lowercase English letters and is non-empty.

*/

/* Solution */

class Solution {
public:
    string capitalizeTitle(string title) {
        string ans="";
        int n = title.size();
        
        if(n==1 || n==2){
            for(int j=0;j<title.size();j++){
                title[j]=tolower(title[j]);
            }

            return title;
        }

        vector<string> v;
        stringstream s(title);
        string str;

        while(s >> str){
            v.push_back(str);
        }


        for(auto i: v){
            cout<<i<<" ";
        }
        cout<<endl;


        for(int i=0;i<v.size();i++){
            if(v[i].size()>2){
                v[i][0]=toupper(v[i][0]);
                for(int j=1;j<v[i].size();j++){
                    v[i][j]=tolower(v[i][j]);
                }
            }
            else{
                for(int j=0;j<v[i].size();j++){
                    v[i][j]=tolower(v[i][j]);
                }
            }
           

            
        }

        for(int i=0;i<v.size();i++){
            if(i!=v.size()-1){
                ans+=v[i];
                ans+=" ";
            }
            else{
                ans+=v[i];
            }
            

        }
        

        return ans;
    }
};
