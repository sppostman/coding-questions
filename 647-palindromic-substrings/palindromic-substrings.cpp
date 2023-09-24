class Solution {
public:
    bool isPalindrome(string s, int start, int end){
        while(start < end)
            if(s[start++] != s[end--])
                return false;
        return true;
    }
    int partition(string s, int idx, int n){
        if(idx == n)    return 0;

        int count = 0;
        for(int end=idx; end<n; end++){
            if(isPalindrome(s, idx, end))
                count += 1 + partition(s, end+1, n);
        }
        return count;
    }
    int countSubstrings(string s) {
        int count=0;
        int n = s.size();
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                if(isPalindrome(s,i,j))
                    count++;
            }
        }
        return count;
        // return partition(s, 0, s.size());
    }
};