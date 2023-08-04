/*

Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.
Note that the same word in the dictionary may be reused multiple times in the segmentation.

Example 1:

Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
  
Example 2:

Input: s = "applepenapple", wordDict = ["apple","pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
Note that you are allowed to reuse a dictionary word.
  
Example 3:

Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
Output: false
 
Constraints:

1 <= s.length <= 300
1 <= wordDict.length <= 1000
1 <= wordDict[i].length <= 20
s and wordDict[i] consist of only lowercase English letters.
All the strings of wordDict are unique.

*/

/* Solution */

class Solution {
public:

    map<string,bool> dp;
    bool dp_fun(set<string> &st,string s){
        if(s.size()<=0){
            return true;
        }

        if(dp.find(s)!=dp.end()){
            return dp[s];
        }

        for(int i=0;i<s.size();i++){
            string str = s.substr(0,i+1);

            if(st.count(str)){
                bool flag = dp_fun(st,s.substr(i+1));
                if(flag){
                    return dp[s] = true;
                }
            }
        }

        return dp[s] = false;

    }
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> st(wordDict.begin(),wordDict.end());

        return dp_fun(st,s);
    }
};
