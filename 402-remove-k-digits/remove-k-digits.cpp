class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        stack<char> st;

        for(int i=0; i<=n; i++){
            while(st.size() > 0 && k>0 && (i==n || num[i] < st.top())){
                st.pop();
                k--;
            }
            if(i<n)
                st.push(num[i]);
        }

        string res = "";
        while(!st.empty()){
            res += st.top();
            st.pop();
        }

        reverse(res.begin(), res.end());
        int j=0;
        while(res[j] == '0')
            j++;
        
        return j==res.size() ? "0" : res.substr(j);
    }
};