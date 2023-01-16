/*

You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the ith interval and intervals is sorted in ascending order by starti. You are also given an interval newInterval = [start, end] that represents the start and end of another interval.

Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).

Return intervals after the insertion.

Example 1:

Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]

Example 2:

Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
 
Constraints:

0 <= intervals.length <= 10^4
intervals[i].length == 2
0 <= starti <= endi <= 10^5
intervals is sorted by starti in ascending order.
newInterval.length == 2
0 <= start <= end <= 10^5

*/

/* Solution */

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        int i = 0;
        int a1 = newInterval[0], a2 = newInterval[1];
        vector<vector<int>> ans;

        while(i<n){

            vector<int> v;

            if(a1 != -1 && a1 < intervals[i][0]){
                v.push_back(a1);
                v.push_back(a2);
                a1 = -1;
            }
            else if(a1 != -1 && a1 <= intervals[i][1]){
                v.push_back(min(intervals[i][0],a1));
                v.push_back(max(intervals[i][1],a2));
                a1 = -1;
                i++;
            }
            else{
                v.push_back(intervals[i][0]);
                v.push_back(intervals[i][1]);
                i++;
            }

            while(i < n && v[1] >= intervals[i][0]){
                v[1] = max(v[1],intervals[i][1]);
                i++;
            }

            ans.push_back(v);

        }

        if(a1 != -1){
            ans.push_back(newInterval);
        }
        return ans;

    }
};
