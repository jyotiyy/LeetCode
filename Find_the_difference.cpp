class Solution {
public:
    char findTheDifference(string s, string t) {
        map<char,int> chars;
        for(char c: s){
            chars[c]++;
        }
        map<char,int> updated;
        for(char x: t){
            updated[x]++;
            if(chars[x] < updated[x]){ 
                return x;
            }
        }
        return 'a';
    }
};
