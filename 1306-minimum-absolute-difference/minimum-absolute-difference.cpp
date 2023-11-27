class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n = arr.size();
        vector<int> a = arr;
        sort(a.begin(), a.end());


        int mindiff = abs(a[1]-a[0]);
        for(int i=1; i<n; i++)
            mindiff = min(mindiff, abs(a[i]-a[i-1]));
        
        printf("diff %d\n", mindiff);
        vector<vector<int>> result;

        for(int i=0; i<n-1; i++){
            if(abs(a[i+1] - a[i]) == mindiff){
                result.push_back({a[i], a[i+1]});
            }
        }

        return result;
    }
};