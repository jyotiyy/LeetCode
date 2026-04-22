class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> ans;
        for(string &s: queries){
            for(string &comp: dictionary){
                int dis =0;
                for(int i = 0; i < s.size(); i++){
                    if(s[i] != comp[i]){
                        ++dis;
                    }
                }
                if(dis <= 2){
                    ans.push_back(s);
                    break;
                }
            }
        }
        return ans;
    }
};
