class Solution {
public:
    int largestInteger(int num) {
        string n=to_string(num);
        string ans;
        vector<int> v;
        vector<int> e;
        vector<int> o;
        for(int i=0;i<n.size();i++){
            v.push_back(int(n[i]));
        }
        
        for(int i=0;i<v.size();i++){
            if(v[i]%2==0){
                e.push_back(int(v[i]));
            }
            else if(v[i]%2!=0){
                o.push_back(int(v[i]));
            }
        }
        
        sort(e.begin(),e.end(),greater<int>());
        sort(o.begin(),o.end(),greater<int>());
        
        vector<char> res(v.size());
        int j=0,k=0;
        for(int i=0;i<v.size();i++){
            if(v[i]%2==0){
                res[i]=e[j];
                j++;
            }
            else{
                res[i]=o[k];
                k++;
            }
        }
        
        for(int j=0;j<res.size();j++){
            ans+=char(res[j]);
        }
        
        return stoi(ans);
        
       /* vector<char> res(v.size());
        int m = 0,p = 1;
        for(int j = 0; j < e.size(); j++){
            res[m] = e[j];
            m=m+2;
        }    
        for(int j = 0; j < o.size(); j++){
            res[p] = o[j];
            p=p+2;
        }    

        /*for(int i=0;i<e.size();i+=2){
            v[i]=e[i];
        }
        for(int i=1;i<o.size();i+=2){
            v[i]=e[i];
        }
        
        
        for(int j=0;j<res.size();j++){
            ans+=char(res[j]);
        }*/
        
        return stoi(ans);
        
        
        
    }
};