//Sort till nth element = nth_element(start,till,end)
//we know to reach v =>  (v-a)%x = 0; and (v-b)%x = 0;
// thus on equalize v%x = a%x = b%x

class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> flatten;
        
        
        for(int row = 0; row < grid.size(); row++){
            for(int col = 0; col < grid[0].size(); col++){
                flatten.push_back(grid[row][col]);
            }
       
        }
        int n = flatten.size();

        nth_element(flatten.begin(),flatten.begin()+n/2,flatten.end());

        int comman = flatten[n/2];
        int res = 0;
        for(int num: flatten){
            if(num%x != comman%x) return -1;
            res += abs(comman-num)/x;
        }
        return res;

    }
};
