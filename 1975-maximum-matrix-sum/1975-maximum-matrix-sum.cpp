class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        
        int m = matrix.size();
        int n = matrix[0].size();

        
         
            int mini = INT_MAX;
            long long totalSum = 0;
           int minusCount = 0;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                // negative count rkh rhe h row ka 
                if(matrix[i][j] <0) 
                {
                    minusCount++;
                }
                totalSum += abs(matrix[i][j]);
                mini = min(mini  ,abs(matrix[i][j]));
            }
        }
            if(minusCount %2 == 1)
            {
                totalSum -= 2LL * mini;
                // ans +=totalSum;
            }
        return totalSum;
    }
};