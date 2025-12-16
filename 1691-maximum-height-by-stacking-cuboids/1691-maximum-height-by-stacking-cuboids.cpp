class Solution {
public:

    bool checkFit(vector<int> &curr , vector <int> &prev)
    {
        if(prev[0] <= curr[0] && prev[1] <= curr[1] && prev[2] <= curr[2] )
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    int solUsingSpaceOptimised(vector<vector<int>>& cuboids )
    {
        int n = cuboids.size();
        vector<int> currRow(n+1 , 0);
        vector<int> nextRow(n+1 , 0);

        for(int curr=n-1; curr>= 0; curr-- )
        {
            for(int prev=curr-1; prev >=-1; prev--)
            {
                // inc case
                int include = 0;

                if(prev == -1 || checkFit(cuboids[curr] , cuboids[prev] ))
                {
                    int maxHeight = cuboids[curr][2];
                    include = maxHeight+ nextRow[curr + 1];
                }
                // exc case
                int exclude = 0 + nextRow[prev + 1];
                currRow[prev + 1] = max(include, exclude);
            }
            nextRow = currRow;
        }
        return nextRow[0];
    }
    int maxHeight(vector<vector<int>>& cuboids) {
        
        for(auto& cub:cuboids)
        {
            sort(cub.begin() , cub.end());
        }
            sort(cuboids.begin() , cuboids.end());

        return solUsingSpaceOptimised(cuboids);
    }
};