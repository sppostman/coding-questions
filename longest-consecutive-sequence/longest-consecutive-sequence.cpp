class Solution
{
    public:
    int longestConsecutive(vector<int> &nums) {
        unordered_set<int> cache;
        for(int n:nums){
            cache.insert(n);
        }

        int longest=0;
        for(int n:nums){
            if(!cache.count(n-1)){
                int curr=1;
                while(cache.count(n+1)){
                    curr++;
                    n++;
                }
                longest = max(longest,curr);
            }
        }

        return longest;
    }
};