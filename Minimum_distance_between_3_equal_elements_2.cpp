//Learnt the importance of Hash Table :)
class Solution {
public:
    
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        map<int,vector<int>> vals;

        for(int i = 0; i < n; i++){
            vals[nums[i]].push_back(i);
        }

        int distance = 1e9;
        for(auto x: vals){
            vector<int> d = x.second;
            if(d.size() >= 3){
                for(int i = 0; i <= d.size()-3; i++){
                    int dist = abs(d[i]-d[i+1])+abs(d[i+1]-d[i+2]) + abs(d[i+2]-d[i]);
                    distance = min(distance,dist);
                }
            }
        }
        return (distance == 1e9) ? -1: distance;


    }
};
