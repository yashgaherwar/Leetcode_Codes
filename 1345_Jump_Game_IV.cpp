/*

Given an array of integers arr, you are initially positioned at the first index of the array.

In one step you can jump from index i to index:

i + 1 where: i + 1 < arr.length.
i - 1 where: i - 1 >= 0.
j where: arr[i] == arr[j] and i != j.
Return the minimum number of steps to reach the last index of the array.

Notice that you can not jump outside of the array at any time.

Example 1:

Input: arr = [100,-23,-23,404,100,23,23,23,3,404]
Output: 3
Explanation: You need three jumps from index 0 --> 4 --> 3 --> 9. Note that index 9 is the last index of the array.

Example 2:

Input: arr = [7]
Output: 0
Explanation: Start index is the last index. You do not need to jump.

Example 3:

Input: arr = [7,6,9,6,9,6,9,7]
Output: 1
Explanation: You can jump directly from index 0 to index 7 which is last index of the array.
 
Constraints:

1 <= arr.length <= 5 * 10^4
-10^8 <= arr[i] <= 10^8

*/

/* Solution */

class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,vector<int>> mp;
        if(n<=1){
            return 0;
        }
        for(int i=0;i<arr.size();i++){
            mp[arr[i]].push_back(i);
        }
        vector<int> vis(n,0);
        queue<int> q;
        q.push(0);
        vis[0]=1;
        int count=0;

        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                auto ft = q.front();
                q.pop();
                if(ft==n-1){
                    return count;
                }
                vector<int> &curr = mp[arr[ft]];
                curr.push_back(ft-1);
                curr.push_back(ft+1);

                for(auto j: curr){
                    if(j>=0 && j<n && vis[j]==0){
                        vis[j]=1;
                        q.push(j);
                    }
                }

                curr.clear();

            }

            count++;
        }

        return -1;

    }
};
