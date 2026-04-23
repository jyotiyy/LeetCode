//For every grp : sum(j: 0->i-1) (ai - aj) + sum(j: i+1->m-1) (aj-ai)

class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,vector<int>> grp;

        for(int i = 0; i < n; i++){
            grp[nums[i]].push_back(i);
        }

        vector<long long> res(n);
        for(const auto&p: grp){
            const auto &grps = p.second;
            long long total = accumulate(grps.begin(),grps.end(),0LL);
            long long prefixTotal = 0;
            for(int i = 0; i< grps.size(); i++){
                res[grps[i]] = total - prefixTotal*2 + grps[i]*(2*i-grps.size());
                prefixTotal += grps[i];
            }
        }
        return res;
    }
};
