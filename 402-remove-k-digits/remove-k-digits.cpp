class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> gt;

        for(char c : num){
            while(k>0 && gt.size()>0 && gt.top() > c){
                gt.pop();
                k--;
            }
            gt.push(c);
        }
        while(k>0 && gt.size()){
            gt.pop();
            k--;
        }

        string res = string(gt.size(), '0');
        for(int i=gt.size()-1; i>=0; i--){
            res[i] = gt.top();
            gt.pop();
        }

        int leadingZeros = 0;
        for(char c : res){
            if(c != '0')
                break;
            leadingZeros++;
        }

        return (leadingZeros == res.size()) ? "0" : res.substr(leadingZeros, res.size()-leadingZeros);
    }
};