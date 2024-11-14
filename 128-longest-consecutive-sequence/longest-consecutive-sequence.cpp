class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> mem;  
        for(auto el : nums) mem.insert(el);

        int ans = 0;
        for(auto el : mem){
            if(mem.count(el-1) == 0){
                int it = el;
                while(mem.count(it)){
                    ans = max(ans, it-el+1);
                    it++;
                }
            }
        }
        return ans;
    }
};