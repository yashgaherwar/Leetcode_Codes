/*
Implement a first in first out (FIFO) queue using only two stacks. The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).
Implement the MyQueue class:
void push(int x) Pushes element x to the back of the queue.
int pop() Removes the element from the front of the queue and returns it.
int peek() Returns the element at the front of the queue.
boolean empty() Returns true if the queue is empty, false otherwise.
Notes:

You must use only standard operations of a stack, which means only push to top, peek/pop from top, size, and is empty operations are valid.
Depending on your language, the stack may not be supported natively. You may simulate a stack using a list or deque (double-ended queue) as long as you use only a stack's standard operations.
 
Example 1:

Input
["MyQueue", "push", "push", "peek", "pop", "empty"]
[[], [1], [2], [], [], []]
Output
[null, null, null, 1, 1, false]

Explanation
MyQueue myQueue = new MyQueue();
myQueue.push(1); // queue is: [1]
myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
myQueue.peek(); // return 1
myQueue.pop(); // return 1, queue is [2]
myQueue.empty(); // return false
 

Constraints:

1 <= x <= 9
At most 100 calls will be made to push, pop, peek, and empty.
All the calls to pop and peek are valid.
 

Follow-up: Can you implement the queue such that each operation is amortized O(1) time complexity? In other words, performing n operations will take overall O(n) time even if one of those operations may take longer.

*/

/* Solution */

class MyQueue {
public:
    stack<int> s1,s2;
    
    MyQueue() {
        
    }
    
    void push(int x) {
        while(!s1.empty()){
            s2.push(s1.top());             // s1 to s2
            s1.pop();
        }
        
        s1.push(x);                        // x to s1
        
        while(!s2.empty()){
            s1.push(s2.top());             // s2 to s1
            s2.pop();
        }
    }
    
    int pop() {
        int tp=s1.top();
        s1.pop();
        return tp;
    }
    
    int peek() {
        return s1.top();
    }
    
    bool empty() {
        return (s1.size()==0);
    }
    
    
    /* Tried for Optimized approach:-*/
//     stack<int> inp,out;
    
//     MyQueue() {
        
//     }
    
//     void push(int x) {
//         inp.push(x);
//     }
    
//     int pop() {
//         if(!out.empty()){
//             out.pop();
//         }
//         else{
//             while(!inp.empty()){
//                 out.push(inp.top());
//                 inp.pop();
//             }
//             out.pop();
//         }
        
//         return out.size();
//     }
    
//     int peek() {
//         if(!out.empty()){
//             return out.top();
//         }
//         else{
//             while(!inp.empty()){
//                 out.push(inp.top());
//                 inp.pop();
//             }
//             return out.top();
//         }
//     }
    
//     bool empty() {
//         return (out.size()==0);
//     }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
