class Solution {
public:
    int reverse(int x){
        int y = 0;
        while(x > 0){
            y = y*10+ (x%10);
            x/=10;
        }
        return y;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int,int> mappings;
        int n = nums.size();
        int ans = n+1;

        unordered_map<int,int> prevs;
        for(int i = 0; i < n; i++){
            int x = nums[i];
            if(prevs.count(x)){
                ans  = min(ans,i-prevs[x]);
            }
            prevs[reverse(x)] = i;
        }
        return ans == n+1 ? -1:ans;
    }
};
