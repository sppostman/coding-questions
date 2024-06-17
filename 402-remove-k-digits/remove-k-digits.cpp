class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> inc;
        int n = num.size();
        for(int i=0; i<=n; i++){
            while(inc.size() && (k>0 && (i==n || num[i]<inc.top()) )){
                inc.pop();
                k--;
            }
            if(i<n)
                inc.push(num[i]);
        }

        string res(inc.size(), '-');
        int i = inc.size()-1;
        while(inc.size()){
            res[i--] = inc.top();
            inc.pop();
        }

        int lz = 0;
        while(lz<res.size() && res[lz]=='0')
            lz++;

        return lz == res.size() ? "0" : res.substr(lz);
    }
};