class Solution {
public:
    string getSmallestString(int n, int k) {
        vector<int> v(n,1);
        
        k=k-n;
        int i=n-1;
        while(k>0){
            if(k>25){
                v[i]=26;
                i--;
                k-=25;
            }
            else{
                v[i]=k+1;
                k-=k;
            }
        }
        
        string res;
        for(int i=0;i<v.size();i++){
            res+=char(v[i]+96);
        }
        
        return res;
    }
};