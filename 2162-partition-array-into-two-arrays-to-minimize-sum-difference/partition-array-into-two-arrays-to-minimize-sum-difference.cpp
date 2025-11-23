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

    int minimumDifference(vector<int>& arr) {
        int n = arr.size();
        int nhalf = n/2;
        
        long long totalSum = accumulate(arr.begin(), arr.end(), 0);
        long long halfSum = totalSum >> 1;

        vector<vector<long long>> sumWays1(nhalf+1), sumWays2(nhalf+1);
        makeSubsets(0, arr, n/2, 0, 0, sumWays1);
        makeSubsets(n/2, arr, n, 0, 0, sumWays2);

        for (auto &p : sumWays2) {
            sort(p.begin(), p.end());
        }
        
        long long ans = LLONG_MAX;
        for(int taken=0; taken<=nhalf; taken++){
            auto &sumList = sumWays1[taken];
        
            // cout<<taken<<" - ";
            auto complementary = sumWays2[nhalf - taken];

            for(auto sum : sumList){
                if(taken == nhalf){
                    ans = min(ans, abs(2 * sum - totalSum));
                    continue;
                }
                
                long long remSum = halfSum - sum;
                // cout<<sum<<"-"<<remSum<<", ";
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
            // cout<<endl;
        }

        return (int)ans;
    }
};