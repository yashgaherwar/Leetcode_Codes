/*

You are playing a game that contains multiple characters, and each of the characters has two main properties: attack and defense. You are given a 2D integer array properties where properties[i] = [attacki, defensei] represents the properties of the ith character in the game.

A character is said to be weak if any other character has both attack and defense levels strictly greater than this character's attack and defense levels. More formally, a character i is said to be weak if there exists another character j where attackj > attacki and defensej > defensei.

Return the number of weak characters.

Example 1:

Input: properties = [[5,5],[6,3],[3,6]]
Output: 0
Explanation: No character has strictly greater attack and defense than the other.

Example 2:

Input: properties = [[2,2],[3,3]]
Output: 1
Explanation: The first character is weak because the second character has a strictly greater attack and defense.

Example 3:

Input: properties = [[1,5],[10,4],[4,3]]
Output: 1
Explanation: The third character is weak because the second character has a strictly greater attack and defense.
 

Constraints:

2 <= properties.length <= 10^5
properties[i].length == 2
1 <= attacki, defensei <= 10^5

*/

/* Solution */

class Solution {
public:
    
    // Sorting and Array Approach
    // Comparator Used for Sorting
    // Time Complexity:- O(n*logn)
    // Space Complexity:- O(1)
    
    static bool cmp(vector<int> &x, vector<int> &y) {
        if(x[0]==y[0]){
            return x[1]>y[1];
        }
        else{
            return x[0]<y[0];
        }
    }
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        int count=0;
        
        int n=properties.size();
        
        sort(properties.begin(),properties.end(),cmp);
        
        int maxi=properties[n-1][1];
        
        for(int j=n-2;j>=0;j--){
            if(properties[j][1] < maxi){
                count++;
                 
            }
           maxi=max(maxi,properties[j][1]);
        }
        
        return count;
       
    }
};
