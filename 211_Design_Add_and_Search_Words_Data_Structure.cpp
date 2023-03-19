/*

Design a data structure that supports adding new words and finding if a string matches any previously added string.

Implement the WordDictionary class:

WordDictionary() Initializes the object.
void addWord(word) Adds word to the data structure, it can be matched later.
bool search(word) Returns true if there is any string in the data structure that matches word or false otherwise. word may contain dots '.' where dots can be matched with any letter.
 
Example:

Input
["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
[[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
Output
[null,null,null,null,false,true,true,true]

Explanation
WordDictionary wordDictionary = new WordDictionary();
wordDictionary.addWord("bad");
wordDictionary.addWord("dad");
wordDictionary.addWord("mad");
wordDictionary.search("pad"); // return False
wordDictionary.search("bad"); // return True
wordDictionary.search(".ad"); // return True
wordDictionary.search("b.."); // return True
 

Constraints:

1 <= word.length <= 25
word in addWord consists of lowercase English letters.
word in search consist of '.' or lowercase English letters.
There will be at most 3 dots in word for search queries.
At most 10^4 calls will be made to addWord and search.

*/


/* Solution */

class TrieNode{
public:
    TrieNode *child[26];
    bool end = false;
    TrieNode(){
        for(int i = 0; i < 26; i++)
            child[i] = NULL;
    }
};

class WordDictionary {
      TrieNode *root ;
public:
    WordDictionary() {
        root =  new TrieNode();
    }
    
    void addWord(string word) {
        int idx = 0;
        TrieNode * node = root;
        for(char c: word) {
            idx = c -'a';
            if(!node->child[idx])
                node->child[idx] = new TrieNode();
            node = node->child[idx];
        }
        node->end = true;
    }
    
    bool search(string word) {
        TrieNode *node = root;
        return search(word, 0, node);
    }
    bool search(string &word, int idx , TrieNode *node ) {
        if(!node) return 0;
        if(idx == word.size()) return node->end;
        if(word[idx] != '.')
            return search(word, idx+1, node->child[word[idx]-'a']);

        for(int key = 0; key< 26; key++)
            if(search(word, idx+1, node->child[key]))
                return true;
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
