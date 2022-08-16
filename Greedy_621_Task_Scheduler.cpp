/*

Given a characters array tasks, representing the tasks a CPU needs to do, where each letter represents a different task. Tasks could be done in any order. Each task is done in one unit of time. For each unit of time, the CPU could complete either one task or just be idle.
However, there is a non-negative integer n that represents the cooldown period between two same tasks (the same letter in the array), that is that there must be at least n units of time between any two same tasks.
Return the least number of units of times that the CPU will take to finish all the given tasks.

Example 1:

Input: tasks = ["A","A","A","B","B","B"], n = 2
Output: 8
Explanation: 
A -> B -> idle -> A -> B -> idle -> A -> B
There is at least 2 units of time between any two same tasks.

Example 2:

Input: tasks = ["A","A","A","B","B","B"], n = 0
Output: 6
Explanation: On this case any permutation of size 6 would work since n = 0.
["A","A","A","B","B","B"]
["A","B","A","B","A","B"]
["B","B","B","A","A","A"]
...
And so on.

Example 3:

Input: tasks = ["A","A","A","A","A","A","B","C","D","E","F","G"], n = 2
Output: 16
Explanation: 
One possible solution is
A -> B -> C -> A -> D -> E -> A -> F -> G -> A -> idle -> idle -> A -> idle -> idle -> A

Constraints:

1 <= task.length <= 104
tasks[i] is upper-case English letter.
The integer n is in the range [0, 100].

*/

/* Solution */

class Solution {
public:
    
    // Time Complexity:- O(nlogn)
    // Space Complexity:- O(n)
    
    int leastInterval(vector<char>& tasks, int n) {
        
        // ans variable for storing least number of units of times that the CPU will take
        int ans=0;
        unordered_map<char,int> mp;
        priority_queue<int> q;
        
        // storing count of each character in map
        for(auto i: tasks){
            mp[i]++;
        }
        
        // Pushing all elements to the Priority Queue
        for(auto j: mp){
            q.push(j.second);
        }
        
        while(!q.empty()){
            
            // tt variable for storing time for executing n task 
            int tt=0;
            
            // vector v for storing the element that is popped from the queue ((element -1) is pushed)
            vector<int> v;
            
            // executing the n+1 task
            for(int i=0;i<=n;i++){
                if(!q.empty()){
                    v.push_back(q.top()-1);
                    q.pop();
                    tt=tt+1;
                }
            }
            
             // If elements in vector are still greater than 0 then again push them back to the priority queue)
            for(auto i: v){
                if(i>0){
                    q.push(i);
                }
            }
            
            // If all the task are over(priority queue is empty) then adding 'tt' to the ans variable otherwise adding n+1 which includes idle time as well
            if(q.empty()){
                ans+=tt;
            }
            else{
                ans+=(n+1);
            }
            
            
        }
        
        // Returning the final least number of units of time
        return ans;
    }
};
