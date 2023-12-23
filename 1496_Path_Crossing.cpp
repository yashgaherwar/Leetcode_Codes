/*

Given a string path, where path[i] = 'N', 'S', 'E' or 'W', each representing moving one unit north, south, east, or west, respectively. You start at the origin (0, 0) on a 2D plane and walk on the path specified by path.

Return true if the path crosses itself at any point, that is, if at any time you are on a location you have previously visited. Return false otherwise.

Example 1:

Input: path = "NES"
Output: false 
Explanation: Notice that the path doesn't cross any point more than once.
  
Example 2:

Input: path = "NESWW"
Output: true
Explanation: Notice that the path visits the origin twice.
 
Constraints:

1 <= path.length <= 104
path[i] is either 'N', 'S', 'E', or 'W'.

*/

/* Solution */

class Solution {
public:
    bool isPathCrossing(string path) {
        int a = 0, b = 0;
        vector<pair<int,int>> v;
        v.push_back({0,0});

        for(auto i: path){
            if(i == 'N'){
                a++;
            }
            else if(i == 'S'){
                a--;
            }
            else if(i == 'E'){
                b++;
            }
            else{
                b--;
            }

            v.push_back({a,b});
        }

        set<pair<int, int>> s(v.begin(), v.end());

        if(s.size() == v.size()){
            return false;
        }

        return true;

    }
};
