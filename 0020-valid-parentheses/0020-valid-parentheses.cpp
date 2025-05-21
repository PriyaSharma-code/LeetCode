class Solution {
public:
    bool isValid(string s) {
        unordered_map<char,char> bracketPair = {
            {'}', '{'},
            {']','['},
            {')', '('}
        };
        stack<char> st;

        for(char c: s){
            if(bracketPair.count(c)){
                if(!st.empty() && bracketPair[c]==st.top()){
                    st.pop();
                }
                else{return false;}
            }
            else{
                st.push(c);
            }
        }
        return st.empty();
    }
};