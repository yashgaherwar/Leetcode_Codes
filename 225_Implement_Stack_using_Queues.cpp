/*
Implement a last-in-first-out (LIFO) stack using only two queues. The implemented stack should support all the functions of a normal stack (push, top, pop, and empty).
Implement the MyStack class:
void push(int x) Pushes element x to the top of the stack.
int pop() Removes the element on the top of the stack and returns it.
int top() Returns the element on the top of the stack.
boolean empty() Returns true if the stack is empty, false otherwise.

Notes:
You must use only standard operations of a queue, which means that only push to back, peek/pop from front, size and is empty operations are valid.
Depending on your language, the queue may not be supported natively. You may simulate a queue using a list or deque (double-ended queue) as long as you use only a queue's standard operations.
 
Example 1:

Input
["MyStack", "push", "push", "top", "pop", "empty"]
[[], [1], [2], [], [], []]
Output
[null, null, null, 2, 2, false]

Explanation
MyStack myStack = new MyStack();
myStack.push(1);
myStack.push(2);
myStack.top(); // return 2
myStack.pop(); // return 2
myStack.empty(); // return False
 
Constraints:

1 <= x <= 9
At most 100 calls will be made to push, pop, top, and empty.
All the calls to pop and top are valid.

Follow-up: Can you implement the stack using only one queue?

*/

/* Solution */

class MyStack {
public:
    
    // Using single Queue:-
    queue<int> q;
    MyStack() {
        
    }
    
    void push(int x) {
         q.push(x);
         for(int i=0;i<q.size()-1;i++){
             q.push(q.front());
             q.pop();

         }
        
        
    }
    
    int pop() {
        int ft=q.front();
        q.pop();
        return ft;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return (q.size()==0);
    }
};


   /* 
   
   // Using Two Queues:-
    
    queue<int> q1,q2;
    
    MyStack() {
        
    }
    
    void push(int x) {
        q2.push(x);                   // x to q2
        
        while(!q1.empty()){
            q2.push(q1.front());      // q1 to q2 (Add element by element)
            q1.pop();
        }
        
        swap(q1,q2);                  // swap q1 and q2
    }
    
    int pop() {
        int ft=q1.front();
        q1.pop();
        return ft;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return (q1.size()==0);
    }
};*/
    

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
