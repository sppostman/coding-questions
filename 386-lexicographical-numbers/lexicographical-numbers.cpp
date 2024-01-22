class Solution {
public:
    void solve(int num, int maxNum, vector<int> &result){
        result.push_back(num);
        // printf("%d < ", num);

        num *= 10;
        for(int i=0; i<10; i++){
            if((num+i) <= maxNum)
                solve(num+i, maxNum, result);
        }
    }
    vector<int> lexicalOrder(int n) {
        // 10 < 100 < 102 < 109 < 11 < 110 < 111 < 114 < 130 < 2 < 21 < 210 < 22 < 220 < 23 < 4 < 5 < 6 < 
        // string arr[] = {"10","11","100", "102","109","111","114", "6", "110", "130", "2", "210", "220","23","21","22", "4", "5"};
        // sort(arr, arr+sizeof(arr) / sizeof(arr[0]));
        // for(string s : arr)
        //     printf("%s < ", s.c_str());

        vector<int> result;
        for(int i=1; i<=min(9, n); i++)
            solve(i, n, result);
        return result;
    }
};