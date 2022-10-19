/*

Given an array of strings words and an integer k, return the k most frequent strings.

Return the answer sorted by the frequency from highest to lowest. Sort the words with the same frequency by their lexicographical order.

Example 1:

Input: words = ["i","love","leetcode","i","love","coding"], k = 2
Output: ["i","love"]
Explanation: "i" and "love" are the two most frequent words.
Note that "i" comes before "love" due to a lower alphabetical order.

Example 2:

Input: words = ["the","day","is","sunny","the","the","the","sunny","is","is"], k = 4
Output: ["the","is","sunny","day"]
Explanation: "the", "is", "sunny" and "day" are the four most frequent words, with the number of occurrence being 4, 3, 2 and 1 respectively.
 

Constraints:

1 <= words.length <= 500
1 <= words[i].length <= 10
words[i] consists of lowercase English letters.
k is in the range [1, The number of unique words[i]]
 
Follow-up: Could you solve it in O(n log(k)) time and O(n) extra space?

*/

/* Solution */

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> ans;
        map<string,int> mp;

        for(auto i: words){
            mp[i]++;
        }

        const auto cmp = [&](string a,string b){
            if(mp[a]==mp[b]){
                return a>b;
            }

            return mp[a]<mp[b];
        };

        priority_queue<string,vector<string>,decltype(cmp)> pq(cmp);

        for(auto j: mp){
            pq.push(j.first);
        }

        while(k-- && !pq.empty()){
            ans.push_back(pq.top());
            pq.pop();
        }

        return ans;
    }
};
