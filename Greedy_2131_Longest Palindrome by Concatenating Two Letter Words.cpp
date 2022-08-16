/*

You are given an array of strings words. Each element of words consists of two lowercase English letters.

Create the longest possible palindrome by selecting some elements from words and concatenating them in any order. Each element can be selected at most once.

Return the length of the longest palindrome that you can create. If it is impossible to create any palindrome, return 0.

A palindrome is a string that reads the same forward and backward.

Example 1:

Input: words = ["lc","cl","gg"]
Output: 6
Explanation: One longest palindrome is "lc" + "gg" + "cl" = "lcggcl", of length 6.
Note that "clgglc" is another longest palindrome that can be created.

Example 2:

Input: words = ["ab","ty","yt","lc","cl","ab"]
Output: 8
Explanation: One longest palindrome is "ty" + "lc" + "cl" + "yt" = "tylcclyt", of length 8.
Note that "lcyttycl" is another longest palindrome that can be created.

Example 3:

Input: words = ["cc","ll","xx"]
Output: 2
Explanation: One longest palindrome is "cc", of length 2.
Note that "ll" is another longest palindrome that can be created, and so is "xx".
 
Constraints:

1 <= words.length <= 105
words[i].length == 2
words[i] consists of lowercase English letters.

*/

/* Solution */

/*

Greedy and Map Approach!!

Complexity:-
Time Complexity:- O(N)
Space Complexity:- O(N)

*/


class Solution {
public:

    int longestPalindrome(vector<string>& words) {
	   // ans variable for storing string that can be added to make the Longest Palindrome
        int ans=0; 
        int flag=0;
		
		// Map for check frequency
        unordered_map<string,int> mp;
		
		// Storing count of each string in map
        for(auto i: words){
            mp[i]++;
        }
		
		// Main Code
        for(auto i: words){
            string a=i;
            reverse(a.begin(),a.end());
            
			// Checking if the reverse of the string i is present or not, if it exist than adding it to the ans variable and reducing the counter of each string from map
            if(mp[i]>0 && mp[a]>0 && a!=i){
                int mini=min(mp[i],mp[a]);
                
                ans+=(mini*4);
                mp[i]-=mini;
                mp[a]-=mini;
            }
            else if(a==i && mp[i]>1){      // if a string comes more than one times whose reverse is also same as that of actual string eg:- (pq kk kk ab) here it is "kk" than we need to add that string in ans variable and reduce its count in map also.
                mp[i]-=2;
                ans+=4;
            }
            else if(a==i && mp[i]>0 && flag==0){     
			// if a string comes exactly one time whose reverse is also same as that of actual string eg:- (pq kk ab) here it is "kk" than we need to add that string in ans variable if and only if flag is zero because it states that none of the string with count one is already added and reduce its count in map also. 
			// ["cc","ll","xx"] for this we need to check this condition
                mp[i]-=1;
                ans+=2;
                flag=1;
            }
        }
        
		// Returning the length of longest Palindrome
        return ans; 
    }
};
