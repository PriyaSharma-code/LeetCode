class Solution {
public:
    bool doesAliceWin(string s) {
        int vow=0;
        int len=s.length();
        for( char a:s){
                if(a=='a'||a=='e'||a=='i'||a=='o'||a=='u'){
                    vow++;
                }
        }
        if(vow==0){
            return false;
        }

        return true;
    }
};