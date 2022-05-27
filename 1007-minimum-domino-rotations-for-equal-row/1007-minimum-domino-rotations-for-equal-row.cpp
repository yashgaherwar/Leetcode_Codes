class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int c1=0,c2=0,c3=0,c4=0;
        int tmp=tops[0];
        int flag=bottoms[0];
        
        for(int i=0;i<tops.size();i++){
            if(c1!=INT_MAX){
                if(tops[i]==tmp){
                    continue;
                }
                else if(bottoms[i]==tmp){
                    c1++;
                }
                else{
                    c1=INT_MAX;
                }
            }
        }   
        
        for(int i=0;i<tops.size();i++){    
            if(c2!=INT_MAX){
                if(bottoms[i]==tmp){
                    continue;
                }
                else if(tops[i]==tmp){
                    c2++;
                }
                else{
                    c2=INT_MAX;
                }
            }
        }
        
        for(int i=0;i<bottoms.size();i++){
            if(c3!=INT_MAX){
                if(bottoms[i]==flag){
                    continue;
                }
                else if(tops[i]==flag){
                    c3++;
                }
                else{
                    c3=INT_MAX;
                }
            }
        }
        
        for(int i=0;i<bottoms.size();i++){
            
            if(c4!=INT_MAX){
                if(tops[i]==flag){
                    continue;
                }
                else if(bottoms[i]==flag){
                    c4++;
                }
                else{
                    c4=INT_MAX;
                }
            }     
        }   
        
        
        int ans=min(min(c1,c2),min(c3,c4));
        if(ans==INT_MAX){
            return -1;
        }
        else{
            return ans;
        }
    }
};