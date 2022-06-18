/*

Design a special dictionary with some words that searchs the words in it by a prefix and a suffix.
Implement the WordFilter class:
WordFilter(string[] words) Initializes the object with the words in the dictionary.
f(string prefix, string suffix) Returns the index of the word in the dictionary, which has the prefix prefix and the suffix suffix. If there is more than one valid index, return the largest of them. If there is no such word in the dictionary, return -1.
 
Example 1:

Input
["WordFilter", "f"]
[[["apple"]], ["a", "e"]]
Output
[null, 0]

Explanation
WordFilter wordFilter = new WordFilter(["apple"]);
wordFilter.f("a", "e"); // return 0, because the word at index 0 has prefix = "a" and suffix = 'e".
 

Constraints:

1 <= words.length <= 15000
1 <= words[i].length <= 10
1 <= prefix.length, suffix.length <= 10
words[i], prefix and suffix consist of lower-case English letters only.
At most 15000 calls will be made to the function f.

*/

/* Solution */

// String, Trie

class WordFilter {
public:
    
    unordered_map<string, int> m1;
    
    WordFilter(vector<string>& words) {
       int m = words.size();
        
        for(int i=0;i<m;i++)
        {
            string word = words[i]; 
            int x = word.size();
            
            
            for(int j=1;j<=x;j++) 
            {
                string a = word.substr(0,j);
                
                for(int k=0;k<x;k++) 
                {
                    string b = word.substr(k,x);
                    m1[a + "|" + b] = i+1; 
                }
            }
        } 
    }
    
    int f(string prefix, string suffix) {
        string k = prefix + "|" + suffix;
        return m1[k]-1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */
