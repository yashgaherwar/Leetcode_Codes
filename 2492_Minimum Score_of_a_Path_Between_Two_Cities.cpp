/*

You are given a positive integer n representing n cities numbered from 1 to n. You are also given a 2D array roads where roads[i] = [ai, bi, distancei] indicates that there is a bidirectional road between cities ai and bi with a distance equal to distancei. The cities graph is not necessarily connected.

The score of a path between two cities is defined as the minimum distance of a road in this path.

Return the minimum possible score of a path between cities 1 and n.

Note:

A path is a sequence of roads between two cities.
It is allowed for a path to contain the same road multiple times, and you can visit cities 1 and n multiple times along the path.
The test cases are generated such that there is at least one path between 1 and n.
 
Example 1:

Input: n = 4, roads = [[1,2,9],[2,3,6],[2,4,5],[1,4,7]]
Output: 5
Explanation: The path from city 1 to 4 with the minimum score is: 1 -> 2 -> 4. The score of this path is min(9,5) = 5.
It can be shown that no other path has less score.

Example 2:

Input: n = 4, roads = [[1,2,2],[1,3,4],[3,4,7]]
Output: 2
Explanation: The path from city 1 to 4 with the minimum score is: 1 -> 2 -> 1 -> 3 -> 4. The score of this path is min(2,2,4,7) = 2.
 
Constraints:

2 <= n <= 10^5
1 <= roads.length <= 10^5
roads[i].length == 3
1 <= ai, bi <= n
ai != bi
1 <= distancei <= 10^4
There are no repeated edges.
There is at least one path between 1 and n.

*/

/* Solution */

class Solution {
public:
    map<int,vector<int>> mp;
    set<int> st;

    void dfs_fun(int a){
        // If node is present in the set then simply return
        if(st.find(a)!=st.end()){
            return;
        }

        // Else update the set and insert that node into the set
        st.insert(a);

        // Recursive call for the connected components for node a (if it is not present in the set)
        for(auto itr: mp[a]){
            if(st.find(itr)==st.end()){
                dfs_fun(itr);
            }
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {

        int ans=INT_MAX;

        // Push all the connected nodes into the map (Just like an adjacency List)
        for(int i=0;i<roads.size();i++){
            mp[roads[i][0]].push_back(roads[i][1]);
            mp[roads[i][1]].push_back(roads[i][0]);
        }

        // DFS call for the updating the connecting components into the set
        dfs_fun(1);

        // Calculating the minimum score possible if it is present in the set
        for(int i=0;i<roads.size();i++){
            if(st.find(roads[i][0])!=st.end()){
                ans=min(ans,roads[i][2]);
            }
        }

        return ans;


    }
};
