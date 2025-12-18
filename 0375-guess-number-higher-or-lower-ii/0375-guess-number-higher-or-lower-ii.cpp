class Solution {
public:

    // recursion wala method 
    // int sol(int start , int end)
    // {
    //     // base case

    //     if(start >= end)
    //     {
    //         return 0;
    //     }

    //     int ans = INT_MAX;

    //     for(int i=start; i<=end; i++ )
    //     {
    //         ans = min(ans , i+ max( sol(start , i-1) , sol(i+1 , end)));
    //     }
    //     return ans;
    // }

    // recursion + memoisation 
    int solUsingMemoisation(int start , int end , vector<vector<int>> &dp)
    {
        // base case
        if(start >= end)
        {
            return 0;
        }
        if(dp[start][end] != -1)
        {
            return dp[start][end];
        }

        int ans = INT_MAX;

        for(int i=start; i<=end; i++ )
        {
            ans = min(ans , i+ max( solUsingMemoisation(start , i-1 , dp) , solUsingMemoisation(i+1 , end ,dp)));
        }
        dp[start][end] = ans;
        return dp[start][end];
    }

    int getMoneyAmount(int n) {
        int start = 1;
        int end  = n;

        vector<vector<int>> dp(n+1 , vector<int>(n+1 , -1));

        int ans = solUsingMemoisation(start , end , dp);
        return ans;
    }
};