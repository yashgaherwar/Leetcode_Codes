/*

Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane, return the maximum number of points that lie on the same straight line.

Example 1:

Input: points = [[1,1],[2,2],[3,3]]
Output: 3

Example 2:

Input: points = [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
Output: 4
 
Constraints:

1 <= points.length <= 300
points[i].length == 2
-10^4 <= xi, yi <= 10^4
All the points are unique.

*/

/* Solution */

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n==1){
            return 1;
        }
        int maxi=1;
        for(int i=0;i<n-1;i++){
            map<double,int> mp;

            for(int j=i+1;j<n;j++){
                if(points[i][0]==points[j][0]){
                    mp[100001]++;
                }
                else{
                    double slope = (double)(points[j][1]-points[i][1])/(double)(points[j][0]-points[i][0]);
                    mp[slope]++;
                }
            }

            int curr_max=0;
            for(auto j: mp){
                curr_max = max(curr_max,j.second);
            }

            maxi=max(maxi,curr_max+1);

            
        }

        return maxi;
    }
};
