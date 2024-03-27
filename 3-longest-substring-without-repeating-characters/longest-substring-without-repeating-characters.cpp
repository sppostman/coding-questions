class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        vector<int> lastOccurence(256, -1); // Has better O(1) than hashmap's O(1)

        int l = 0, r=0;
        int largest = 0;
        while(r<n){
            char c = s[r];

            if(lastOccurence[c] < l){
                largest = max(largest, r-l+1);
            } else {
                l = lastOccurence[c]+1;
            }
            lastOccurence[c] = r;
            r++;
        }
        return largest;
    }
        

    int lengthOfLongestSubstringSpaceNotOptimal(string s) {
        int l=0, length = 0, largest = 0;
        unordered_map<char, int> lastOccurence;

        char ch = 'a';
        for(int i=0; i<s.length(); i++){
            ch = s.at(i);
            if(lastOccurence.find(ch) != lastOccurence.end() && lastOccurence[ch] >= l){
                int thisLength = i - l;
                largest = max(thisLength, largest);

                l = lastOccurence[ch] + 1;
                lastOccurence.erase(ch);
            }
            lastOccurence[ch] = i;
        }
        int thisLength = s.length() - l;
        largest = max(largest, thisLength);
        return largest;
    }
};