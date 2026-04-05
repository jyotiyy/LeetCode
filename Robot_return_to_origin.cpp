class Solution {
public:
    bool judgeCircle(string moves) {
        int n = moves.size();
        int currx = 0;
        int curry = 0;
        for(int i = 0; i < n; i++){
            if(moves[i] == 'L'){
                currx--;
            }else if(moves[i] == 'R'){
                currx++;
            }else if(moves[i] == 'U'){
                curry++;
            }else{
                curry--;
            }
        }
        return (currx == 0 && curry == 0);
    }
};
