class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        int v = matrix.size();
        vector<int> ans(v,0);
        
        for(int i = 0; i < v; i++){
            for(int j = 0; j < v; j++){
                if(i < j){
                    if(matrix[i][j]){
                    ans[i]++;
                    ans[j]++;
                }
                }
            }
        }
        return ans;
    }
};
