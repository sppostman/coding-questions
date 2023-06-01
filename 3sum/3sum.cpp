class Solution
{
    public:
        vector<vector < int>> threeSum(vector<int> &a)
        {
            // for every 1, 2 pointers - O(n^2)
            int n = a.size();
            vector<vector < int>> result;
            sort(a.begin(), a.end());
            int l,h;

            for (int i = 0; i < n; i++){
                if(i!=0 && a[i-1]==a[i])    continue;   // Skip duplicate i
                l = i+1;
                h=n-1;
                while(l<h){
                    if(a[l]+a[h]+a[i] == 0){
                        result.push_back({a[l],a[h],a[i]});
                        do {
                            l++;
                        } while(l<h && a[l-1] == a[l]);
                        do {
                            h--;
                        } while(h>l && a[h+1] == a[h]);
                    }
                    else if(a[l]+a[h]+a[i] < 0)
                        l++;
                    else
                        h--;
                }
            }


            return result;

            // Hashmap, O(n^2), O(n+m) (m for no. of unique triplets)
            // Gives tle
            // int n = a.size();
            // vector<vector < int>> result;
            // set<string> occured;
            // unordered_map<int, int> counter;
            // for (int n: a) counter[n]++;
            // string triplet;
            // int mn, secondMin, thirdMin;
            // for (int i = 0; i < n; i++)
            // {
            //     counter[a[i]]--;
            //     for (int j = i + 1; j < n; j++)
            //     {
            //         counter[a[j]]--;
            //         int target = -(a[i] + a[j]);
            //         if (counter[target])
            //         {
            //             // printf("Found target for %d,%d => %d, at %d\n",a[i],a[j],target, counter[target]);
            //             if (a[i] <= a[j] && a[i] <= target)
            //             {
            //                 mn = a[i];
            //                 secondMin = min(a[j], target);
            //             }
            //             else
            //             {
            //                 mn = min(a[j], target);
            //                 secondMin = min(a[i], max(target, a[j]));
            //             }
            //             thirdMin = -(mn+secondMin);
            //             triplet = to_string(mn) + "-" + to_string(secondMin) + "-" + to_string(thirdMin);

            //             if (!occured.count(triplet))
            //             {
            //                 result.push_back({ mn,
            //                     secondMin,
            //                     thirdMin });
            //                 occured.insert(triplet);
            //             }
            //         }
            //         counter[a[j]]++;
            //     }
            //     counter[a[i]]++;
            // }
            // return result;
        }
};