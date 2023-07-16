class Solution
{
    public:
        vector<vector < int>> threeSum(vector<int> &a)
        {
            // Sort-O(N) + for every el, traverse remaining - O(N^2)
            int n = a.size();
            vector<vector < int>> result;
            sort(a.begin(), a.end());
            
            int l,r;
            for(int i=0; i<n; i++){
                if(i>0 && a[i]==a[i-1])    continue;

                l=i+1;
                r=n-1;
                int required = -a[i];
                while(l<r){
                    if(a[l]+a[r] == required){
                        result.push_back({a[i],a[l],a[r]});
                        do {
                            l++;
                        }while(l<r && a[l-1]==a[l]);
                        do {
                            r--;
                        }while(l<r && a[r]==a[r+1]);
                    }
                    else if(a[l]+a[r] < required)
                        l++;
                    else
                        r--;
                }
            }
            return result;


            // Hashmap, O(n^2), O(n+m) (m for no. of unique triplets)
            // Gives tle
            // int n = a.size();
            // set<vector<int>> uniqueTriplets;
            // unordered_map<int,int> counter;
            // for(int n:a)
            //     counter[n]++;
            // for(int i=0; i<n; i++){
            //     counter[a[i]]--;
            //     for(int j=i+1; j<n; j++){
            //         counter[a[j]]--;
            //         int required = -(a[i]+a[j]);
            //         if(counter[required]){
            //             vector<int> triplet = {a[i], a[j], required};
            //             sort(triplet.begin(), triplet.end());
            //             uniqueTriplets.insert(triplet);
            //         }
            //         counter[a[j]]++;
            //     }
            //     counter[a[i]]++;
            // }
            // vector<vector<int>> result(
            //     uniqueTriplets.begin(),
            //     uniqueTriplets.end()
            // );
            // return result;
        }
};