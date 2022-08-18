/*

You are given an integer array arr. You can choose a set of integers and remove all the occurrences of these integers in the array.
Return the minimum size of the set so that at least half of the integers of the array are removed.

Example 1:

Input: arr = [3,3,3,3,5,5,5,2,2,7]
Output: 2
Explanation: Choosing {3,7} will make the new array [5,5,5,2,2] which has size 5 (i.e equal to half of the size of the old array).
Possible sets of size 2 are {3,5},{3,2},{5,2}.
Choosing set {2,7} is not possible as it will make the new array [3,3,3,3,5,5,5] which has a size greater than half of the size of the old array.

Example 2:

Input: arr = [7,7,7,7,7,7]
Output: 1
Explanation: The only possible set you can choose is {7}. This will make the new array empty.
 
Constraints:

2 <= arr.length <= 10^5
arr.length is even.
1 <= arr[i] <= 10^5

*/

/* Solution */

class Solution {
public:
    
    //Priority Queue and Map Approach!!
    //Time Complexity:- O(N)
    //Space Complexity:- O(N)
  
    int minSetSize(vector<int>& arr) {
        
        // count variable for storing the number of elements that need to be removed
        int count=0;
        unordered_map<int,int> mp;
        
		    // Storing frequency of each element in map
        for(auto i: arr){
            mp[i]++;
        }
        
        // Pushing elements to Priority queue according to their frequency
        priority_queue<int> pq;
        
        for(auto j: mp){
            pq.push(j.second);
        }
        
        // n is the half of size of array
        int n=arr.size()/2;
        
        while(!pq.empty() && n!=0){
            // if top element at priority queue is less than or equal to n then we need to remove that element so for that we increased the counter and update the value of n. Otherwise if it is greater than we simply increment the counter and come out of the loop and hence return the count.
            if(pq.top()<=n){
                n=n-pq.top();
                pq.pop();
                count++;
            }
            else{
               if((n-pq.top())<0){
                   count++;
                   n=0;
               }
            }
        }
        
        // Returning the final result
        return count;
        
        
    }
};
