class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        string ans;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push(i);
            }
            else if(!st.empty() && s[i]==')'){
                st.pop();
            }
            else if(s[i]==')'){
                s[i]='.';
            }
            
        }
        
        while(!st.empty()){
            s[st.top()]='.';
            st.pop();
        }
        
        for(int i=0;i<s.size();i++){
            if(s[i]!='.'){
                ans.push_back(s[i]);
            }
        }
        
        return ans;
        
        /*string ans;
        stack<char> st;
        
        for(int i=0;i<s.size();i++){
            if(s[i]!='(' && s[i]!=')'){
                ans.push_back(s[i]);
            }
            else if(!st.empty() && st.top()=='('){
                if(s[i]==')'){
                    ans.push_back(s[i]);
                    st.pop();
                }
                else{
                    ans.push_back(s[i]);
                    st.push(s[i]);
                }
                
            }
            else if(s[i]=='('){
                st.push(s[i]);
                ans.push_back(s[i]);
                
            }
        }
         //return ans;
        
        //cout<<ans[1];
        if(st.empty()){
            return ans;
        }
        else{
            return "";
        }
        */
        
    }
};