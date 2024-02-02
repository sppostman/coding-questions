class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n=matrix.size(), m=matrix[0].size();
        vector<vector<int>> prefixsum(n, vector<int>(m,0));


        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                prefixsum[i][j] = matrix[i][j];
                prefixsum[i][j] += i>0 ? prefixsum[i-1][j] : 0;
                prefixsum[i][j] += j>0 ? prefixsum[i][j-1] : 0;
                prefixsum[i][j] -= (j>0 && i>0) ? prefixsum[i-1][j-1] : 0;
                // printf("%d\t", prefixsum[i][j]);
            }
            // printf("\n");
        }

        int ans = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                
                for(int x=i; x<n; x++){
                    for(int y=j; y<m; y++){
                        int sum = prefixsum[x][y];
                        sum -= i>0 ? prefixsum[i-1][y] : 0;
                        sum -= j>0 ? prefixsum[x][j-1] : 0;
                        sum += (i>0 && j>0) ? prefixsum[i-1][j-1] : 0;

                        if(sum == target)
                            ans++;
                    }
                }

            }
        }

        return ans;
    }
};