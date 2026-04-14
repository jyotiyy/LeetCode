class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int distance = INT_MAX;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == target){
                distance = min(distance,abs(start-i));
            }
        }
        return distance;
    }
};
