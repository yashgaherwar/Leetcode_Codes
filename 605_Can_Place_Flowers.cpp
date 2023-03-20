/*

You have a long flowerbed in which some of the plots are planted, and some are not. However, flowers cannot be planted in adjacent plots.

Given an integer array flowerbed containing 0's and 1's, where 0 means empty and 1 means not empty, and an integer n, return if n new flowers can be planted in the flowerbed without violating the no-adjacent-flowers rule.

Example 1:

Input: flowerbed = [1,0,0,0,1], n = 1
Output: true

Example 2:

Input: flowerbed = [1,0,0,0,1], n = 2
Output: false
 
Constraints:

1 <= flowerbed.length <= 2 * 10^4
flowerbed[i] is 0 or 1.
There are no two adjacent flowers in flowerbed.
0 <= n <= flowerbed.length

*/

/* Solution */

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count=0;
        if(n==0){
            return true;
        }
        if(flowerbed.size()==1){
            if(flowerbed[0]==0 && n==1){
                return true;
            }
            else{
                return false;
            }
        }
        if(flowerbed[0]==0 && flowerbed[1]==0){
            flowerbed[0]=1;
            count++;
        }
        for(int i=1;i<flowerbed.size()-1;i++){
            if(flowerbed[i]==0){
                if(flowerbed[i+1]==0 && flowerbed[i-1]==0){
                    flowerbed[i]=1;
                    count++;
                }
            }
        }

        if(flowerbed[(flowerbed.size()-1)]==0 && flowerbed[flowerbed.size()-2]==0){
            flowerbed[0]=1;
            count++;
        }

        if(count>=n){
            return true;
        }
        else{
            return false;
        }
    }
};
