//Hash map :))))
class Solution {
public:
    string majorityFrequencyGroup(string s) {
        vector<int> freq(26,0);
        for (char& c : s)
            freq[c-'a']++;
        
        unordered_map<int,int> count;
        for(int i = 0; i < 26; i++){
            if(freq[i] != 0){
                count[freq[i]]++;
            }
        }

        int bestfreq = 0;
        int maxcount = 0;
        for(auto& [f,c] : count){
            if(c > maxcount || (c == maxcount && f > bestfreq)){
                maxcount = c;
                bestfreq = f;
            }
        }

        string res;
        for(int i = 0; i < 26; i++){
            if(freq[i] == bestfreq){
                res += char(i+'a');
            }
        }
        return res;
        
    }
};
