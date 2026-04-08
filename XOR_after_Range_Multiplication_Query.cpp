class Solution {
public:
   
    const int MOD = 1e9 + 7;
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        long long ans = 0;
        for(auto q: queries){
            long long idx = q[0];
            while(idx <= q[1]){
                nums[idx] = 1LL*nums[idx]*q[3]%MOD;
               
                idx+=q[2];
            }
        }
        for(auto x: nums){
            ans ^= x;
        }
        return ans;
    }
};
