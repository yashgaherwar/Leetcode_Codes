/*

You are given an integer array matchsticks where matchsticks[i] is the length of the ith matchstick. You want to use all the matchsticks to make one square. You should not break any stick, but you can link them up, and each matchstick must be used exactly one time.
Return true if you can make this square and false otherwise.

Example 1:

Input: matchsticks = [1,1,2,2,2]
Output: true
Explanation: You can form a square with length 2, one side of the square came two sticks with length 1.

Example 2:

Input: matchsticks = [3,3,3,3,4]
Output: false
Explanation: You cannot find a way to form a square with all the matchsticks.

Constraints:

1 <= matchsticks.length <= 15
1 <= matchsticks[i] <= 108

*/

/* Solution */

class Solution {
public:
    int n;
    vector <int> matchsticks;
    
    int target = 0;
    bool generate(int level,int a,int b,int c, int d){
        
        if(level == n){
            return a == target && b == target && c == target && d == target; 
        }
        
        
        if(a+matchsticks[level]<=target){
           if(generate(level+1,a+matchsticks[level],b,c,d)){
             return true;  
           } 
        }
        
        
        if(b+matchsticks[level]<=target){
            if(generate(level+1,a,b+matchsticks[level],c,d)){
                return true;
            }    
        }
        
        
        if(c+matchsticks[level]<=target){
           if(generate(level+1,a,b,c+matchsticks[level],d)){
               return true;
           }    
        }
        
      
        if(d+matchsticks[level]<=target){
           if(generate(level+1,a,b,c,d+matchsticks[level])){
               return true;
           }    
        }
        
        return false;
    }
    
    bool makesquare(vector<int>& _matchsticks) {
        matchsticks = _matchsticks;
        n = matchsticks.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=matchsticks[i];
        }    
        
        if(sum%4 !=0){
            return false;
        }    
        
        
        target = sum/4;
        
        sort(matchsticks.rbegin(),matchsticks.rend());
        
        return generate(0,0,0,0,0);
        }
    };
