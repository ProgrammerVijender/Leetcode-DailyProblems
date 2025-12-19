class Solution {
public:
    long long int MOD = 1000000007;
    // recursion :--
    // int solveUsingRecursion(int n, int k, int target,
    //                         int diceUsed, int currSum) {

    //     if (diceUsed == n && currSum == target) {
    //         return 1;
    //     }

    //     if (diceUsed == n && currSum != target) {
    //         return 0;
    //     }

    //     if (currSum == target && diceUsed != n) {
    //         return 0;
    //     }

    //     int ans = 0;
    //     for (int face = 1; face <= k; face++) {
    //         ans = ans + solveUsingRecursion(n, k, target,diceUsed + 1,currSum + face);
    //     }

    //     return ans;
    // }

    // Memoisation :---
//     int solveUsingMemo(int n, int k, int target,
//                   int diceUsed, int currSum,
//                   vector<vector<int>>& dp) {

//     if (diceUsed == n && currSum == target) {
//         return 1;
//     }

//     if (diceUsed == n && currSum != target) {
//         return 0;
//     }

//     if (currSum == target && diceUsed != n) {
//         return 0;
//     }

//     if (dp[diceUsed][currSum] != -1) {
//         return dp[diceUsed][currSum];
//     }

//     int ans = 0;
//     for (int face = 1; face <= k; face++) {
//         int recAns = 0;
//         if (currSum + face <= target) {
//             recAns = solveUsingMemo(
//                         n, k, target,
//                         diceUsed + 1,
//                         currSum + face,
//                         dp);
//         }
//         ans = (ans % MOD+ recAns% MOD)% MOD;
//     }

//     return dp[diceUsed][currSum] = ans;
// }
    

    // Tabulation Method :-----
    // int solveUsingTabulation(int n, int k, int target) {

    //     vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));

    //     // base case
    //     dp[n][target] = 1;

    //     for (int dice = n - 1; dice >= 0; dice--) {
    //         for (int sum = target; sum >= 0; sum--) {

    //             int ans = 0;

    //             for (int face = 1; face <= k; face++) {
    //                 int recAns = 0;

    //                 if (sum + face <= target) {
    //                     recAns = dp[dice + 1][sum + face];
    //                 }

    //                 ans = (ans % MOD + recAns % MOD) % MOD;
    //             }

    //             dp[dice][sum] = ans;
    //         }
    //     }

    //     return dp[0][0];
    // }
    
    int solveUsingTabulationSO(int n, int k, int target)
    {
         vector<int> curr(target + 1, 0);
        vector<int> next(target + 1, 0);

        // base case
        next[target] = 1;

        for (int dice = n - 1; dice >= 0; dice--) {

            for (int sum = target; sum >= 0; sum--) {

                int ans = 0;

                for (int face = 1; face <= k; face++) {
                    int recAns = 0;

                    if (sum + face <= target) {
                        recAns = next[sum + face];
                    }

                    ans = (ans % MOD + recAns % MOD) % MOD;
                }

                curr[sum] = ans;
            }

            next = curr;
        }

        return next[0];
    }

    
    int numRollsToTarget(int n, int k, int target) {
        int diceUsed = 0;
        int currSum = 0;
        // recursion
        // int ans = solveUsingRecursion(n, k, target,diceUsed, currSum);

        // memoisation
        // vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
        // int ans = solveUsingMemo(n, k, target,diceUsed, currSum , dp);


        // TABULATION 
        // return solveUsingTabulation(n,k,target);

        // tabulation +Space optimised
        return solveUsingTabulationSO(n,k,target);

        // return ans;
    }
};