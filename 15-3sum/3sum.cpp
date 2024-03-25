class Solution
{
    public:
        vector<vector < int>> threeSum(vector<int> &arr)
        {
            int n = arr.size();

            // Sort-O(N^2) + for every el, traverse remaining - O(N^2)
            vector<vector<int>> result;
            sort(arr.begin(), arr.end());
            for(int i=0; i<n; i++){
                if(i>0 && arr[i] == arr[i-1])
                    continue;
                int l = i+1;
                int r = n-1;
                int req = -arr[i];
                while(l<r){
                    if(arr[l]+arr[r] == req){
                        result.push_back({arr[i], arr[l], arr[r]});
                        do{
                            l++;
                        }while(l<r && arr[l]==arr[l-1]);
                        do{
                            r--;
                        }while(r>l && arr[r]==arr[r+1]);
                    } else if(arr[l]+arr[r] < req){
                        l++;
                    } else {
                        r--;
                    }
                }
            }
            return result;
            // -4 -1 -1 0 1 2

            
            // int l,r;
            // for(int i=0; i<n; i++){
            //     if(i>0 && a[i]==a[i-1])    continue;

            //     l=i+1;
            //     r=n-1;
            //     int required = -a[i];
            //     while(l<r){
            //         if(a[l]+a[r] == required){
            //             result.push_back({a[i],a[l],a[r]});
            //             do {
            //                 l++;
            //             }while(l<r && a[l-1]==a[l]);
            //             do {
            //                 r--;
            //             }while(l<r && a[r]==a[r+1]);
            //         }
            //         else if(a[l]+a[r] < required)
            //             l++;
            //         else
            //             r--;
            //     }
            // }
            // return result;


            // // TLE - Hashmap, O(n^2), O(n+m) (m for no. of unique triplets)
            // set<vector<int>> uniqueTriplets;
            // unordered_map<int, int> counter;
            // for(int el : arr)
            //     counter[el]++;
            // for(int i=0; i<n; i++){
            //     int a = arr[i];
            //     counter[a]--;

            //     for(int j=i+1; j<n; j++){
            //         int b = arr[j];
            //         counter[b]--;

            //         int need = -(a+b);
            //         if(counter[need] > 0){
            //             vector<int> triplet = {a,b,need};
            //             sort(triplet.begin(),triplet.end());
            //             uniqueTriplets.insert(triplet);
            //         }

            //         counter[b]++;
            //     }
            //     counter[a]++;
            // }
            // // for(auto triplet : uniqueTriplets)
            // //     result.push_back(triplet);
            // vector<vector<int>> result(
            //     uniqueTriplets.begin(),
            //     uniqueTriplets.end()
            // );
            // return result;
        }
};