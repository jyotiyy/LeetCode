class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        int f = 0;
        int numSum = accumulate(nums.begin(),nums.end(),0);
        for(int i = 0; i < n; i++){
             f+=i*nums[i];
        }

        int res = f;
        for(int i = n-1; i >= 0; i--){
            f=  f + numSum - n* nums[i];
            res = max(res,f);
        }
        return res;
    }
};
