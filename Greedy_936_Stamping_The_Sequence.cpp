/*

You are given two strings stamp and target. Initially, there is a string s of length target.length with all s[i] == '?'.

In one turn, you can place stamp over s and replace every letter in the s with the corresponding letter from stamp.

For example, if stamp = "abc" and target = "abcba", then s is "?????" initially. In one turn you can:
place stamp at index 0 of s to obtain "abc??",
place stamp at index 1 of s to obtain "?abc?", or
place stamp at index 2 of s to obtain "??abc".
Note that stamp must be fully contained in the boundaries of s in order to stamp (i.e., you cannot place stamp at index 3 of s).
We want to convert s to target using at most 10 * target.length turns.

Return an array of the index of the left-most letter being stamped at each turn. If we cannot obtain target from s within 10 * target.length turns, return an empty array.

Example 1:

Input: stamp = "abc", target = "ababc"
Output: [0,2]
Explanation: Initially s = "?????".
- Place stamp at index 0 to get "abc??".
- Place stamp at index 2 to get "ababc".
[1,0,2] would also be accepted as an answer, as well as some other answers.

Example 2:

Input: stamp = "abca", target = "aabcaca"
Output: [3,0,1]
Explanation: Initially s = "???????".
- Place stamp at index 3 to get "???abca".
- Place stamp at index 0 to get "abcabca".
- Place stamp at index 1 to get "aabcaca".
 

Constraints:

1 <= stamp.length <= target.length <= 1000
stamp and target consist of lowercase English letters.

*/

/* Solution */

class Solution {
public:
    int if_replace_fun(vector<char> &v2,vector<char> &v1,int j,int stampLen){
        char ch='?';
        for(int i=0;i<stampLen;i++){
            if(v2[i+j]!=ch && v2[i+j]!=v1[i]){
                return 0;
            }
        }
        
        return 1;
    }
    
    int replace_fun(vector<char> &v2,int j,int res,int stampLen){
        char ch='?';
        for(int i=0;i<stampLen;i++){
            if(v2[i+j]!=ch){
                v2[i+j]=ch;
                res=res+1;
            }
        }
        
        return res;
    }
    vector<int> movesToStamp(string stamp, string target) {
        int stampLen=stamp.size();
        int targetLen=target.size();
        int res=0;
        int substringLen = targetLen - stampLen;
        
        vector<char> v1;
        vector<char> v2;
        vector<int> vis(targetLen,0);
        vector<int> ans;
        vector<int> final_res;
        
        for(auto i: stamp){
            v1.push_back(i);
        }
        
        for(auto i: target){
            v2.push_back(i);
        }
        
        while(res!=targetLen){
            int flag=0;
            for(int j=0;j<=substringLen;j++){
                if(vis[j]==0 && if_replace_fun(v2,v1,j,stampLen)==1){
                    res=replace_fun(v2,j,res,stampLen);
                    ans.push_back(j);
                    vis[j]=1;
                    flag=1;
                    if(res==targetLen){
                        break;
                    }
                    
                }
            }
            
            if(flag==0){
                return {};
            }
        }
        
        for(int j=ans.size()-1;j>=0;j--){
            final_res.push_back(ans[j]);
        }
        return final_res;
    }
};
