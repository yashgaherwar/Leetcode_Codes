class Solution {
public:
    #define ll long long
    long long minimalKSum(vector<int>& nums, int k) {
        map<int,int> m;
        int n=nums.size();
        for(int i=0;i<n;i++){
            m[nums[i]]++;
        }
        ll j=1,sum=0;
        
        for(auto i: m){
            ll st=j;
            ll ed=i.first;
            if((ed-st)<k){
                k-=(ed-st);
            }
            else{
                break;
            }
            
            sum+=((ed-1)*ed/2 - (st-1)*st/2);
            j=ed+1;
        }
        
        ll st=j;
        ll ed=st+k;
        
        sum+=((ed-1)*ed/2 - (st-1)*st/2);
        return sum;
        
        
        
        /*unordered_map<ll,ll> m;
        int n=nums.size();
        for(int i=0;i<n;i++){
            m[nums[i]]++;
        }
        ll j=1,sum=0;
        while(k!=0){
            if(m[j]<1){
                sum+=j;
                k--;
            }
            j++;
        }
        
        return sum;*/
    }
};