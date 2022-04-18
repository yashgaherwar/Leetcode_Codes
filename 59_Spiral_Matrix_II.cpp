/*
Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.

Example 1:

Input: n = 3
Output: [[1,2,3],[8,9,4],[7,6,5]]

Example 2:

Input: n = 1
Output: [[1]]
*/

/*Solution*/

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> v(n,vector<int> (n));
        int r1=0,r2=n-1,c1=0,c2=n-1,curr=1;
        
        while(r1<=r2 && c1<=c2){
            for(int i=c1;i<=c2;i++){
                v[r1][i]=curr++;
            }
            r1++;
            for(int i=r1;i<=r2;i++){
                v[i][c2]=curr++;
            }
            c2--;
            for(int i=c2;i>=c1;i--){
                v[r2][i]=curr++;
            }
            r2--;
            for(int i=r2;i>=r1;i--){
                v[i][c1]=curr++;
            }
            c1++;
        }
        
        return v;
    }
};
