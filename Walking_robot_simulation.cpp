//lEARNT HASH MAPPING IN THIS 
//HASH MULTIPLIER ** REDUCES THE PROBLEM 
class Solution {
public:
    static const long long HASH_MULTIPLIER = 60013;
    long long hashCord(long long x,long long y){
        return x+HASH_MULTIPLIER*y;
    }
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<long long> obstacleSet;
        for(auto &obs: obstacles){
            obstacleSet.insert(hashCord(obs[0],obs[1]));
        }

        vector<vector<int>> directions = {{0,1},{1,0},{0,-1},{-1,0}};

        vector<int> currPos = {0,0};
        int maxDist = 0;
        int currDirection = 0; // 0:North ||  1:East  || 2:South || 3:West 

        for(int command: commands){
            if(command == -1){
                currDirection = (currDirection + 1)%4;
                continue;
            }
            if(command == -2){
                currDirection = (currDirection + 3)%4;
            }

            vector<int> direction = directions[currDirection];
            for(int step = 0; step < command; step++){
                int nextX = currPos[0] + direction[0];
                int nextY = currPos[1] + direction[1];
                if(obstacleSet.contains(hashCord(nextX,nextY))){
                    break;
                }
                currPos[0] = nextX;
                currPos[1] = nextY;
            }
            maxDist = max(maxDist,currPos[0]*currPos[0] + currPos[1]*currPos[1]);
        }
        return maxDist;
    }
};
