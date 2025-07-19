class Solution {
public:
    bool isValid(string word) {
        unordered_set<char> vowels ={'a','e','i','o','u','A','E','I','O','U'};
        unordered_set<char> consonant;
        for(char c ='A'; c<='Z';c++){
            if(vowels.find(c) == vowels.end()){
                consonant.insert(c);
                consonant.insert(c+32);
            }
        }
        bool hasvowel = false;
        bool hasconsonant = false;
        for(char c : word){
            if(!isalnum(c)){
                return false;
            }
            if(vowels.find(c)!= vowels.end()){
                hasvowel = true;
            }
            if(consonant.find(c)!= consonant.end()){
                hasconsonant =  true;
            }
        }
        return word.length() >=3 && hasvowel && hasconsonant; 
    }
};