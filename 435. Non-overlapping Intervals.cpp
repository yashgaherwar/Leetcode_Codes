/*

Given an array of intervals intervals where intervals[i] = [starti, endi], return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

Example 1:

Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
Output: 1
Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.
  
Example 2:

Input: intervals = [[1,2],[1,2],[1,2]]
Output: 2
Explanation: You need to remove two [1,2] to make the rest of the intervals non-overlapping.
  
Example 3:

Input: intervals = [[1,2],[2,3]]
Output: 0
Explanation: You don't need to remove any of the intervals since they're already non-overlapping.
 
Constraints:

1 <= intervals.length <= 10^5
intervals[i].length == 2
-5 * 10^4 <= starti < endi <= 5 * 10^4

*/

/* Solution */

// Time Complexity:- O(n*log(n))
// Space Complexity:- O(1)

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size(),cnt = 0;
        sort(intervals.begin(),intervals.end());
        int a = intervals[0][1];

        for(int i=1;i<n;i++){
            if(a > intervals[i][0]){
                cnt++;
                a = min(a,intervals[i][1]);
            }
            else{
                a = intervals[i][1];
            }
        }

        return cnt;

    }
};
