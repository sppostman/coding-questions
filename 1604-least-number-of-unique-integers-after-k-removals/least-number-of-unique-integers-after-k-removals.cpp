class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int> counter;
        for(auto &n : arr)  counter[n]++;

        if(k == 0)
            return counter.size();

        vector<int> counts;
        for(const auto &[el, count] : counter)
            counts.push_back(count);
        
        sort(counts.begin(), counts.end());

        int nunique = counts.size();
        for(int i=0; i<nunique; i++){
            k -= counts[i];
            if(k<0)
                return nunique-i;
        }
        return 0;
    }
};