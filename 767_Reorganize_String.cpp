/*

Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.

Return any possible rearrangement of s or return "" if not possible.

Example 1:

Input: s = "aab"
Output: "aba"
  
Example 2:

Input: s = "aaab"
Output: ""
  
Constraints:

1 <= s.length <= 500
s consists of lowercase English letters.

*/

/* Solution */


class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> mp;
        string ans;

        for(auto i: s){
            mp[i]++;
        }

        priority_queue<pair<int,char>> pq;

        for(auto i: mp){
            pq.push({i.second,i.first});
        }

        while(pq.size()>=2){
            auto itr1 = pq.top(); 
            pq.pop();
            auto itr2 = pq.top();
            pq.pop();
            
            
            ans+=itr1.second;
            ans+=itr2.second;

            itr1.first--;
            itr2.first--;
          
            // cout<<ans<<" ";
            // cout<<itr1.second<<" ";
            // cout<<itr2.second<<" ";

            if(itr1.first>0){
                pq.push({itr1.first, itr1.second});
            }

            if(itr2.first>0){
                pq.push({itr2.first, itr2.second});
            }
        }

        if(pq.size()>0){
            auto itr1 = pq.top();
            pq.pop();

            // cout<< itr1.first <<" ";
            // cout<< itr1.second <<" ";

            if(itr1.first > 1){
                return "";
            }
            ans+=itr1.second;
            itr1.first--;
        }

        return ans;    
    }
};
