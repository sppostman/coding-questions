class Solution {
public:
    int generateSqd(int digits){
        int n=1;
        for(int i=2; i<=digits; i++){
            n *= 10;
            n += i;
        }
        return n;
    }
    vector<int> sequentialDigits(int low, int high) {
        int current = generateSqd(log10(low)+1);

        vector<int> result;

        int n=10;
        while(true){
            if(current <= high){
                if(current >= low)
                    result.push_back(current);
            } else
                break;

            int lastdigit = current%10;

            if(lastdigit == 9){
                current = generateSqd(log10(current)+2);
            } else {
                int digits = log10(current)+1;
                current = current % int(pow(10, digits-1));

                current *= 10;
                current += lastdigit+1;
            }
        }

        return result;
    }
};