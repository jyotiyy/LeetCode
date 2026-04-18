class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> range(2);
        range[0] = binarySearch(nums,target,true);
        range[1] = binarySearch(nums,target,false);
        return range;
    }
    int binarySearch(vector<int> nums,int t,bool searchforleft){
        int idx = -1;
        int l = 0;
        int r = nums.size()-1;

        while(l <= r){
            int m = l+(r-l)/2;
            if(nums[m] > t){
                r = m-1;
            }else if(nums[m] < t){
                l = m+1;
            }else{
                idx = m;
                if(searchforleft){
                    r = m-1;
                }else{
                    l = m+1;
                }
            }
        }
        return idx;
    }
};
