/*

The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value, and the median is the mean of the two middle values.
For example, for arr = [2,3,4], the median is 3.
For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
Implement the MedianFinder class:

MedianFinder() initializes the MedianFinder object.
void addNum(int num) adds the integer num from the data stream to the data structure.
double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual answer will be accepted.
 
Example 1:

Input
["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
[[], [1], [2], [], [3], []]
Output
[null, null, null, 1.5, null, 2.0]

Explanation
MedianFinder medianFinder = new MedianFinder();
medianFinder.addNum(1);    // arr = [1]
medianFinder.addNum(2);    // arr = [1, 2]
medianFinder.findMedian(); // return 1.5 (i.e., (1 + 2) / 2)
medianFinder.addNum(3);    // arr[1, 2, 3]
medianFinder.findMedian(); // return 2.0
 
Constraints:

-10^5 <= num <= 10^5
There will be at least one element in the data structure before calling findMedian.
At most 5 * 10^4 calls will be made to addNum and findMedian.
 

Follow up:

If all integer numbers from the stream are in the range [0, 100], how would you optimize your solution?
If 99% of all integer numbers from the stream are in the range [0, 100], how would you optimize your solution?

*/

/* Solution */

class MedianFinder {
public:
    priority_queue<int> max_pq;
    priority_queue <int, vector<int>, greater<int>>  min_pq;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(max_pq.size() > 0 && max_pq.top()<num){
            min_pq.push(num);
        }
        else{
            max_pq.push(num);
        }

        if(min_pq.size()>max_pq.size()+1){
            max_pq.push(min_pq.top());
            min_pq.pop();
        }
        if(max_pq.size()>min_pq.size()+1){
            min_pq.push(max_pq.top());
            max_pq.pop();
        }
    }
    
    double findMedian() {
        
       if(max_pq.size()>min_pq.size()){
           return max_pq.top();
       }
       else if(min_pq.size()>max_pq.size()){
           return min_pq.top();
       }
       else{
           return (min_pq.top()+max_pq.top())/2.0;
       }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */


