/*
Note: This is a companion problem to the System Design problem: Design TinyURL.
TinyURL is a URL shortening service where you enter a URL such as https://leetcode.com/problems/design-tinyurl and it returns a short URL such as http://tinyurl.com/4e9iAk. Design a class to encode a URL and decode a tiny URL.
There is no restriction on how your encode/decode algorithm should work. You just need to ensure that a URL can be encoded to a tiny URL and the tiny URL can be decoded to the original URL.

Implement the Solution class:

Solution() Initializes the object of the system.
String encode(String longUrl) Returns a tiny URL for the given longUrl.
String decode(String shortUrl) Returns the original long URL for the given shortUrl. It is guaranteed that the given shortUrl was encoded by the same object.
 

Example 1:

Input: url = "https://leetcode.com/problems/design-tinyurl"
Output: "https://leetcode.com/problems/design-tinyurl"

Explanation:
Solution obj = new Solution();
string tiny = obj.encode(url); // returns the encoded tiny url.
string ans = obj.decode(tiny); // returns the original url after deconding it.
 

Constraints:

1 <= url.length <= 104
url is guranteed to be a valid URL.
*/

/*Solution Approach 1*/

class Solution {
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
       return longUrl;
        
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
       return shortUrl;
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));




/*Solution Approach 2*/
/* Using Unordered Map*/
class Solution {
    unordered_map<string,string> m1;
    unordered_map<string,string> m2;
private: 
   unsigned int fun(string &s){
        unsigned int a=0x811c9dc5;
        unsigned int b=0x1000193;
        
        for(int i=0;i<s.size();i++){
            a=a^s[i];
            a=a*b;
        }
        
        return a;
        
    }
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        m1[longUrl]= "http://tinyurl.com/" + to_string(fun(longUrl));
        m2[m1[longUrl]]=longUrl;
        return m1[longUrl];
        
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
       return m2[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
