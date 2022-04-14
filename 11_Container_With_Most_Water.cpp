/*
You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
Find two lines that together with the x-axis form a container, such that the container contains the most water.
Return the maximum amount of water a container can store.
Notice that you may not slant the container.
  
Example 1:
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.

Example 2:
Input: height = [1,1]
Output: 1

Constraints:

n == height.length
2 <= n <= 105
0 <= height[i] <= 104
*/

/*Solution*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        /*Two pointer Approach:-*/
        
        int l=0,r=height.size()-1;
        int mini,maxi=0;
        while(l<r){
            mini=min(height[l],height[r]);
            maxi=max(maxi,mini*(r-l));
            
            if(height[l]<height[r]){
                l++;
            }
            else{
                r--;
            }
        }
        
        return maxi;
        
        
        
       /*
       Brute force Approach:-
       
       int mini,maxi=0;
       
       for(int i=0;i<height.size()-1;i++){
           for(int j=i+1;j<height.size();j++){
                 mini=min(height[i],height[j]);
                 maxi=max(maxi,mini*(j-i));
           }  
        }
        
        return maxi;
        */
        
        
    }
};
