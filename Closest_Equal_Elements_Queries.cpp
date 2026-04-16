class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();

        unordered_map<int,vector<int>> numPos;
        for(int i = 0; i < n; i++){
            numPos[nums[i]].push_back(i);
        }

        for(auto &[_,pos]: numPos){
            int x = pos[0];
            pos.insert(pos.begin(),pos.back()-n);
            pos.push_back(x+n);
        }
        int m = queries.size();
        for(int i = 0; i < m; i++){
            int x = nums[queries[i]];
            if(numPos[x].size() == 3){
                queries[i] = -1;
                continue;
            }
            int pos = lower_bound(numPos[x].begin(),numPos[x].end(),queries[i]) - numPos[x].begin();
            queries[i] = min(numPos[x][pos+1]-numPos[x][pos],numPos[x][pos]-numPos[x][pos-1]);
            
        }
        return queries;

    }
};
