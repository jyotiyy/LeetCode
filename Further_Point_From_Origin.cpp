class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int n = moves.length();
        int steps = 0;

        int l = 0;
        int r = 0;
        for(int i =0; i <n; i++){
            if(moves[i] == 'L') l++;
            if(moves[i] == 'R') r++;
        }
        int em = n-(l+r);
        return max(l,r)+em-min(l,r);
    }
};
