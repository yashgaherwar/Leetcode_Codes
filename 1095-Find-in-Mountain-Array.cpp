/*


(This problem is an interactive problem.)

You may recall that an array arr is a mountain array if and only if:

arr.length >= 3
There exists some i with 0 < i < arr.length - 1 such that:
arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
Given a mountain array mountainArr, return the minimum index such that mountainArr.get(index) == target. If such an index does not exist, return -1.

You cannot access the mountain array directly. You may only access the array using a MountainArray interface:

MountainArray.get(k) returns the element of the array at index k (0-indexed).
MountainArray.length() returns the length of the array.

Example 1:

Input: array = [1,2,3,4,5,3,1], target = 3
Output: 2
Explanation: 3 exists in the array, at index=2 and index=5. Return the minimum index, which is 2.

Example 2:

Input: array = [0,1,2,4,2,1], target = 3
Output: -1
Explanation: 3 does not exist in the array, so we return -1.
 
Constraints:

3 <= mountain_arr.length() <= 10000
0 <= target <= 1000000000
0 <= mountain_arr.get(index) <= 1000000000

*/

/* Solution */

/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int l1=0, r1 = n - 1;

        while(l1 < r1){
            int mid = (l1 + (r1 - l1)/2);
            if(mountainArr.get(mid) < mountainArr.get(mid+1)){
                l1 = mid + 1;
            }
            else{
                r1 = mid;
            }
        }

        int l2 = 0, r2 = l1;

        while(l2 <= r2){
            int mid = (l2 + (r2 - l2)/2);

            if(mountainArr.get(mid) == target){
                return mid;
            }
            else if(mountainArr.get(mid) < target){
                l2 = mid + 1;
            }
            else{
                r2 = mid - 1;
            }
        }

        int l3 = l1, r3 = n - 1;

        while(l3 <= r3){
            int mid = (l3 + (r3 - l3)/2);

            if(mountainArr.get(mid) == target){
                return mid;
            }
            else if(mountainArr.get(mid) < target){
                r3 = mid - 1;
            }
            else{
                l3 = mid + 1;
            }
        }

        return -1;

    }
};
