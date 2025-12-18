class Solution {
public:
    // recursion :--
    // int solveUsingRecusrion(int n, int k, int target)
    // {
        
    //     if(n== 0 && target == 0)
    //     {
    //         return 1;
    //     }

    //     if(n != 0 && target == 0)
    //     {
    //         return 0;
    //     }

    //     if(n == 0 && target != 0)
    //     {
    //         return 0;
    //     }
        
        
    //     int ans = 0;

    //     for(int i=0; i<=k; i++)
    //     {
    //         ans += solveUsingRecusrion(n-1, k,target - i);
    //     }
    //     return ans;
    // }

    // memoisation :---
    long long int MOD = 1000000007;
    int solveUsingMemoisation(int n, int k, int target , vector<vector<int> >& dp)
    {
        if (target < 0)
        {return 0;}
        
        if(n== 0 && target == 0)
        {
            return 1;
        }

        if(n != 0 && target == 0)
        {
            return 0;
        }

        if(n == 0 && target != 0)
        {
            return 0;
        }

        if(dp[n][target] != -1)
        {
            return dp[n][target];
        }
        
        
        int ans = 0;

        for(int i=1; i<=k; i++)
        {
             ans = (ans + solveUsingMemoisation(n - 1, k, target - i, dp)) % MOD;
        }
        return dp[n][target] = ans;
    }


    int numRollsToTarget(int n, int k, int target) {
        // return solveUsingRecusrion(n , k , target);

        vector<vector<int>> dp(n+1,vector<int>(target+1 , -1));
        return solveUsingMemoisation( n ,k , target , dp);

    }
};