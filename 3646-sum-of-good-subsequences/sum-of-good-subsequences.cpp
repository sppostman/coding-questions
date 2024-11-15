const int MOD = 1e9+7;

class Solution {
public:
    unsigned long long modMultiply(unsigned long long num) {
        return num % MOD;
    }

    template <typename... Args>
    unsigned long long modMultiply(unsigned long long num, Args... args) {
        return (num % MOD * modMultiply(args...)) % MOD;
    }


    int sumOfGoodSubsequences(vector<int>& nums) {
        
        int n =nums.size();
        vector<unsigned long long> pref(n, 1), suff(n, 1);
        map<int, unsigned long long> taken;
        map<int, unsigned long long> takenRev;

        for(int i=0; i<n; i++){
            unsigned long long el = nums[i];
            pref[i] = (taken[el-1] + taken[el+1] + 1) % MOD;
            taken[el] = (taken[el] + pref[i]) % MOD;
        }
        for(int i=n-1; i>=0; i--){
            unsigned long long el = nums[i];
            suff[i] = (takenRev[el-1] + takenRev[el+1] + 1) % MOD;
            takenRev[el] = (takenRev[el] + suff[i]) % MOD;
        }

        unsigned long long res = 0;
        for(int i=0; i<n; i++){
            res = (res + modMultiply(pref[i], suff[i], nums[i])) %MOD;
        }
        return res;
    }
};