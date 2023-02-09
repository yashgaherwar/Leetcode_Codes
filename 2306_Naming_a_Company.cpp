/*

You are given an array of strings ideas that represents a list of names to be used in the process of naming a company. The process of naming a company is as follows:

Choose 2 distinct names from ideas, call them ideaA and ideaB.
Swap the first letters of ideaA and ideaB with each other.
If both of the new names are not found in the original ideas, then the name ideaA ideaB (the concatenation of ideaA and ideaB, separated by a space) is a valid company name.
Otherwise, it is not a valid name.
Return the number of distinct valid names for the company.

Example 1:

Input: ideas = ["coffee","donuts","time","toffee"]
Output: 6
Explanation: The following selections are valid:
- ("coffee", "donuts"): The company name created is "doffee conuts".
- ("donuts", "coffee"): The company name created is "conuts doffee".
- ("donuts", "time"): The company name created is "tonuts dime".
- ("donuts", "toffee"): The company name created is "tonuts doffee".
- ("time", "donuts"): The company name created is "dime tonuts".
- ("toffee", "donuts"): The company name created is "doffee tonuts".
Therefore, there are a total of 6 distinct company names.

The following are some examples of invalid selections:
- ("coffee", "time"): The name "toffee" formed after swapping already exists in the original array.
- ("time", "toffee"): Both names are still the same after swapping and exist in the original array.
- ("coffee", "toffee"): Both names formed after swapping already exist in the original array.

Example 2:

Input: ideas = ["lack","back"]
Output: 0
Explanation: There are no valid selections. Therefore, 0 is returned.
 
Constraints:

2 <= ideas.length <= 5 * 10^4
1 <= ideas[i].length <= 10
ideas[i] consists of lowercase English letters.
All the strings in ideas are unique.

*/

/* Solution */

class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        long long n=ideas.size(),count=0;
        //map<string,int> mp;
        unordered_set<string> s;
        vector<vector<long long>> v(26,vector<long long> (26,0));
        for(auto i: ideas){
            //mp[i]++;
            s.insert(i);
        }

        for(auto i: ideas){
            char ch1=i[0];
            for(char j='a';j<='z';j++){
                i[0]=j;
                if(s.find(i)==s.end()){
                    // mp[ideas[i]]++;
                    // mp[ideas[j]]++;
                    //cout<<ideas[i]<<" "<<ideas[j]<<endl;
                    //count++;
                    v[ch1-'a'][j-'a']+=1;
                }
            }
        }
        for(int i=0;i<26;i++){
            for(int j=0;j<26;j++){
                count+=(v[j][i] * v[i][j]);
            }
        }
        return count;

    }
};
