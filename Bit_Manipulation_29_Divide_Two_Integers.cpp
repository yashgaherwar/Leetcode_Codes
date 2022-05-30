/*

Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.
The integer division should truncate toward zero, which means losing its fractional part. For example, 8.345 would be truncated to 8, and -2.7335 would be truncated to -2.
Return the quotient after dividing dividend by divisor.
Note: Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−231, 231 − 1]. For this problem, if the quotient is strictly greater than 231 - 1, then return 231 - 1, and if the quotient is strictly less than -231, then return -231.

Example 1:

Input: dividend = 10, divisor = 3
Output: 3
Explanation: 10/3 = 3.33333.. which is truncated to 3.

Example 2:

Input: dividend = 7, divisor = -3
Output: -2
Explanation: 7/-3 = -2.33333.. which is truncated to -2.
 
Constraints:

-231 <= dividend, divisor <= 231 - 1
divisor != 0

*/

/* Solution */

class Solution {
public:
    
    // Bit Manipulation Technique
    // Time Complexity:-  O(log(N^2))
    // Space Complexity:- O(1)
    
    int divide(int dividend, int divisor) {
        long long ans=0;
        
        if(dividend==INT_MIN && divisor==-1){
            return INT_MAX;
        }
         if(dividend==INT_MIN && divisor==1){
            return INT_MIN;
        }
        
        long long flag=0;
        if((dividend>=0 && divisor>=0)||(dividend<=0 && divisor<=0)){
            flag=1;
        }
       
        
        long long dd=abs(dividend);
        long long di=abs(divisor);
        
        while((dd-di)>=0){
            long long cc=0;
            while((dd-(di<<1<<cc))>=0){
                cc++;
            }
            
            ans=ans+(1<<cc);
            dd=dd-(di<<cc);
            
        }
        
        if(flag==1){
            return ans;
        }
        else{
            return (-ans);
        }
        
        
    }
};
