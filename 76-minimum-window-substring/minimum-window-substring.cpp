class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<int> tchar(256, 0);
        for(auto c : t)
            tchar[c]++;

        int i=0, j=0;
        int available = 0;
        int minWindow = INT_MAX, minWindowI = -1;
        while(j<n){
            char c = s[j];
            available += tchar[c]>0;
            tchar[c]--;

            while(available == m){
                if(j-i+1 < minWindow){
                    minWindow = j-i+1;
                    minWindowI = i;
                }
                tchar[s[i]]++;
                available -= tchar[s[i]] > 0;
                i++;
            }

            j++;
        }
        return minWindowI == -1 ? "" : s.substr(minWindowI, minWindow);

        // vector<int> tchar(256, 0);
        // for(auto c : t) tchar[c]++;

        // int best = INT_MAX;
        // int bestI = -1;

        // int i=0, j=0;
        // int gotten = 0;
        // while(j<n){
        //     char c=s[j];
        //     if(tchar[c] > 0)
        //         gotten++;
        //     tchar[c]--;

        //     while(gotten == t.size()){
        //         if(j-i+1 < best){
        //             best = j-i+1;
        //             bestI = i;
        //         }
        //         tchar[s[i]]++;
        //         if(tchar[s[i]] > 0)
        //             gotten--;
        //         i++;
        //     }

        //     j++;
        // }
        // return bestI == -1 ? "" : s.substr(bestI, best);

        // for(int i=0; i<n; i++){
        //     vector<int> rem = tchar; // Copied
        //     int gotten = 0;
        //     for(int j=i; j<n; j++){
        //         char c = s[j];
        //         if(rem[c] > 0)
        //             gotten++;
        //         rem[c]--;
                
        //         if(gotten == t.size()){
        //             if(j-i+1 < best){
        //                 best = j-i+1;
        //                 bestI = i;
        //             }
        //             break;
        //         }
        //     }
        // }
        // return bestI == -1 ? "" : s.substr(bestI, best);
    }
};