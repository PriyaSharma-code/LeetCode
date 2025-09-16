class Solution {
public:
    int canBeTypedWords(string& text, string& brokenLetters) {
        bitset<26> checkKey;
        int res{};
        for(const int& c : brokenLetters){
            checkKey[c-97] = true;
        }
        bool ok = true;
        for(const int& c : text){
            if(c == 32){
                if(ok)
                    ++res;
                else
                    ok = true;
            }

            if(ok && checkKey[c-97])
                ok = false;
        }
        return res+ok;
    }
};