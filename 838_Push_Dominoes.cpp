/*

There are n dominoes in a line, and we place each domino vertically upright. In the beginning, we simultaneously push some of the dominoes either to the left or to the right.

After each second, each domino that is falling to the left pushes the adjacent domino on the left. Similarly, the dominoes falling to the right push their adjacent dominoes standing on the right.

When a vertical domino has dominoes falling on it from both sides, it stays still due to the balance of the forces.

For the purposes of this question, we will consider that a falling domino expends no additional force to a falling or already fallen domino.

You are given a string dominoes representing the initial state where:

dominoes[i] = 'L', if the ith domino has been pushed to the left,
dominoes[i] = 'R', if the ith domino has been pushed to the right, and
dominoes[i] = '.', if the ith domino has not been pushed.
Return a string representing the final state.

Example 1:

Input: dominoes = "RR.L"
Output: "RR.L"
Explanation: The first domino expends no additional force on the second domino.

Example 2:

Input: dominoes = ".L.R...LR..L.."
Output: "LL.RR.LLRRLL.."
 

Constraints:

n == dominoes.length
1 <= n <= 10^5
dominoes[i] is either 'L', 'R', or '.'.

*/

/* Solution */

class Solution {
public:
    string pushDominoes(string dominoes) {
        int n=dominoes.size();
        
        int i=0,j=n-1;

        string str="";
        
        vector<int> l(n,0);  
        vector<int> r(n,0);
        
        int prev=0,cnt=0;
        while(i<n)
        {
            if(dominoes[prev]=='R' && dominoes[i]=='.'){
                cnt++;
            }
            else {
                prev=i;
                cnt=0;
            }
            r[i]=cnt;
            i++;
        }
      
        cnt =0;
        prev=j;
        
        while(j>=0)
        {
            if(dominoes[prev]=='L' && dominoes[j]=='.'){
                cnt++;
            }
            else {
                prev=j;
                cnt=0;
            }
            l[j]=cnt;
            j--;
        }
           
        for(int i=0;i<n;i++)
        {
            if(l[i] < r[i] && dominoes[i]=='.' && l[i]!=0){  
                dominoes[i]='L';
            }
            if(l[i] > r[i] && dominoes[i]=='.' && r[i]==0){
                dominoes[i]='L';
            }
            if(l[i] > r[i] && dominoes[i]=='.' && r[i]!=0){
                dominoes[i]='R';
            }
            if(l[i] < r[i] && dominoes[i]=='.' && l[i]==0){
                dominoes[i]='R';
            }
            if(l[i] == r[i] && dominoes[i]=='.'){
                dominoes[i]='.';
            }
           
        }
        
        return dominoes;

    }
};
