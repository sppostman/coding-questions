class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> counter;
        for(auto s : strs){
            string copy = s;
            sort(copy.begin(), copy.end());
            counter[copy].push_back(s);
        }

        // map<map<char,int>, vector<string>> counter;

        // for(auto s : strs){
        //     map<char,int> individual;
        //     for(char c:s)
        //         individual[c]++;
        //     if(counter.count(individual))
        //         counter[individual].push_back(s);
        //     else
        //         counter[individual] = {s};
        // }

        vector<vector<string>> res;
        for(auto entry : counter)
            res.push_back(entry.second);
        return res;
    }
};