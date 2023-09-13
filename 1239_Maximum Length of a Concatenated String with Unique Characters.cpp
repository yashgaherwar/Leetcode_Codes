/*

You are given an array of strings arr. A string s is formed by the concatenation of a subsequence of arr that has unique characters.
Return the maximum possible length of s.
A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.

Example 1:

Input: arr = ["un","iq","ue"]
Output: 4
Explanation: All the valid concatenations are:
- ""
- "un"
- "iq"
- "ue"
- "uniq" ("un" + "iq")
- "ique" ("iq" + "ue")
Maximum length is 4.

Example 2:

Input: arr = ["cha","r","act","ers"]
Output: 6
Explanation: Possible longest valid concatenations are "chaers" ("cha" + "ers") and "acters" ("act" + "ers").

Example 3:

Input: arr = ["abcdefghijklmnopqrstuvwxyz"]
Output: 26
Explanation: The only string in arr has all 26 characters.
 
Constraints:

1 <= arr.length <= 16
1 <= arr[i].length <= 26
arr[i] contains only lowercase English letters.

*/

/* Solution */

class Solution {
public:

    // Backtracking Approach
    
    map<int,int> mp;
    int res=0;

    void fun(vector<string> &arr,int l,int r){

        int count=0;

        for(int i=0;i<26;i++){
            if(mp[i]==1){
                count++;
            }
            if(mp[i]>1){
                return;
            }
        }

        res=max(res,count);

        for(int i=l;i<r;i++){
            for(auto j: arr[i]){
                mp[j-'a']++;
            }

            fun(arr,i+1,arr.size());

            for(auto j: arr[i]){
                mp[j-'a']--;
            }   
        } 
    }
    int maxLength(vector<string>& arr) {
        fun(arr,0,arr.size());

        return res;
    }
};
