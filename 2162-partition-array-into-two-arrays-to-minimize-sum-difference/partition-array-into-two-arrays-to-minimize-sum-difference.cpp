class Solution {
public:
    void makeSubsets(long long i, vector<int> &arr, int n, long long currSum, int taken,
        vector<vector<long long>> &sumWays){
        if(i == n){
            sumWays[taken].push_back(currSum);
            return;
        }

        makeSubsets(i+1, arr, n, currSum, taken, sumWays);
        makeSubsets(i+1, arr, n, currSum + arr[i], taken+1, sumWays);
    }

    pair<vector<vector<long long>>, vector<vector<long long>>> makeSubsetsBitMan(vector<int> &arr){
        int n = arr.size() >> 1;
        vector<vector<long long>> sumWays1(n+1);
        vector<vector<long long>> sumWays2(n+1);

        for(int mask = 0; mask < (1<<n); mask++){
            int sum1 = 0, sum2 = 0;
            int taken = 0;
            for(int i=0; i<n; i++){
                if(mask & (1<<i)){
                    taken++;
                    sum1 += arr[i];
                    sum2 += arr[i+n];
                }
            }
            sumWays1[taken].push_back(sum1);
            sumWays2[taken].push_back(sum2);
        }

        return {sumWays1, sumWays2};
    }

    int minimumDifference(vector<int>& arr) {
        int n = arr.size();
        int nhalf = n/2;
        
        long long totalSum = accumulate(arr.begin(), arr.end(), 0);
        long long halfSum = totalSum >> 1;

        // vector<vector<long long>> sumWays1(nhalf+1), sumWays2(nhalf+1);
        // makeSubsets(0, arr, n/2, 0, 0, sumWays1);
        // makeSubsets(n/2, arr, n, 0, 0, sumWays2);

        auto [sumWays1, sumWays2] = makeSubsetsBitMan(arr);

        for (auto &p : sumWays2) {
            sort(p.begin(), p.end());
        }
        
        long long ans = LLONG_MAX;
        for(int taken=0; taken<=nhalf; taken++){
            auto &sumList = sumWays1[taken];
        
            auto complementary = sumWays2[nhalf - taken];

            for(auto sum : sumList){
                if(taken == nhalf){
                    ans = min(ans, abs(2 * sum - totalSum));
                    continue;
                }
                
                long long remSum = halfSum - sum;
                auto lb = lower_bound(complementary.begin(), complementary.end(), remSum);
            
                if(lb != complementary.end())
                    ans = min(ans, abs(2*(sum + *lb) - totalSum));
                if(ans == 0)
                    return 0;

                int upi = upper_bound(complementary.begin(), complementary.end(), remSum) 
                            - complementary.begin();
                if(upi < complementary.size())
                    ans = min(ans, abs(2*(sum + complementary[upi]) - totalSum));
                if(upi > 0)
                    ans = min(ans, abs(2*(sum + complementary[upi-1]) - totalSum));
            }
        }

        return (int)ans;
    }
};