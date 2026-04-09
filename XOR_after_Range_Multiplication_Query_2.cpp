class Solution {
public:
    
    long long binpow(long long a, long long e, int md){
        long long res = 1;
        while(e > 0){
            if(e & 1){
                res = (res * a) % md;
            }
            a = (a * a) % md;
            e >>= 1;
        }
        return res;
    }

    long long mdinv(long long n, int md){
        return binpow(n, md - 2, md);
    }

    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), md = 1e9 + 7;
        int limit = sqrt(n);

        unordered_map<int, vector<vector<int>>> mp;

        // Step 1: Split queries
        for(auto &q : queries){
            int l = q[0], r = q[1], k = q[2], v = q[3];

            if(k >= limit){
                for(int j = l; j <= r; j += k){
                    nums[j] = (1LL * nums[j] * v) % md;
                }
            } else {
                mp[k].push_back(q);
            }
        }

        // Step 2: Process small k using diff array
        for(auto &[k, qs] : mp){
            vector<long long> diff(n, 1);

            for(auto &q : qs){
                int l = q[0], r = q[1], v = q[3];

                diff[l] = (diff[l] * v) % md;

                
                int next = l + ((r - l) / k + 1) * k;
                if(next < n){
                    diff[next] = (diff[next] * mdinv(v, md)) % md;
                }
            }

            // Prefix propagation
            for(int i = 0; i < n; i++){
                if(i >= k){
                    diff[i] = (diff[i] * diff[i - k]) % md;
                }
                nums[i] = (1LL * nums[i] * diff[i]) % md;
            }
        }

        // Step 3: XOR result
        int ans = 0;
        for(auto x : nums){
            ans ^= x;
        }

        return ans;
    }
};
