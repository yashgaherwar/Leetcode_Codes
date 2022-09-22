/*

Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

Example 1:

Input: s = "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"

Example 2:

Input: s = "God Ding"
Output: "doG gniD"
 
Constraints:

1 <= s.length <= 5 * 10^4
s contains printable ASCII characters.
s does not contain any leading or trailing spaces.
There is at least one word in s.
All the words in s are separated by a single space.

*/

/* Solution */

class Solution {
public:
    string reverseWords(string s) {
        vector<string> ans;
        stringstream str(s);
        string obj;
        
        while(str >> obj){
            reverse(obj.begin(),obj.end());
            ans.push_back(obj);
        }
        
        string res="";
        
        for(int i=0;i<ans.size();i++){
            res+=ans[i];
            if(i!=ans.size()-1){
               res+=' '; 
            }  
        }
        
        return res;        
        
        /*
        string ans;
        vector<string> v;
        reverse(s.begin(),s.end());
        istringstream str(s);
        string itr;
        while (str >> itr){
           v.push_back(itr); 
        }
        reverse(v.begin(),v.end());
        
        for(int i=0;i<v.size();i++){
            if(i!=v.size()-1) ans+=v[i]+' ';
            else ans+=v[i]; 
        }
        return ans;
        */
    }
};
