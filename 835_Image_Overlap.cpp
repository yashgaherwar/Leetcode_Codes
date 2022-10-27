/*

You are given two images, img1 and img2, represented as binary, square matrices of size n x n. A binary matrix has only 0s and 1s as values.

We translate one image however we choose by sliding all the 1 bits left, right, up, and/or down any number of units. We then place it on top of the other image. We can then calculate the overlap by counting the number of positions that have a 1 in both images.

Note also that a translation does not include any kind of rotation. Any 1 bits that are translated outside of the matrix borders are erased.

Return the largest possible overlap.

Example 1:

Input: img1 = [[1,1,0],[0,1,0],[0,1,0]], img2 = [[0,0,0],[0,1,1],[0,0,1]]
Output: 3
Explanation: We translate img1 to right by 1 unit and down by 1 unit.
The number of positions that have a 1 in both images is 3 (shown in red).

Example 2:

Input: img1 = [[1]], img2 = [[1]]
Output: 1

Example 3:

Input: img1 = [[0]], img2 = [[0]]
Output: 0
 
Constraints:

n == img1.length == img1[i].length
n == img2.length == img2[i].length
1 <= n <= 30
img1[i][j] is either 0 or 1.
img2[i][j] is either 0 or 1.

*/

/* Solution */

class Solution {
public:

    // Vector Pair and Map Approach
    // Time Complexity:- O(M*M)
    // Space Complexity:- O(M)
  
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {

        int m=img1.size();
        int n=img2.size();
        vector<pair<int,int>> arr1,arr2;
        map<pair<int,int>,int> mp;
        int maxi=INT_MIN;

        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++){
                if(img1[i][j]==1){
                    arr1.push_back({i,j});
                }
                if(img2[i][j]==1){
                    arr2.push_back({i,j});
                }
            }
        } 

        for(int i=0;i<arr1.size();i++){
            for(int j=0;j<arr2.size();j++){
                int a=arr1[i].first-arr2[j].first;
                int b=arr1[i].second-arr2[j].second;

                mp[{a,b}]++;
            }
        }

        for(auto j: mp){
            maxi=max(maxi,j.second);
        }

        if(maxi==INT_MIN){
            return 0;
        }

        return maxi;
    }
};
