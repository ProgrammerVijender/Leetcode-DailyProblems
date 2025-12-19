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

    int solveUsingMemo(int n, int k, int target,
                  int diceUsed, int currSum,
                  vector<vector<int>>& dp) {

    if (diceUsed == n && currSum == target) {
        return 1;
    }

    if (diceUsed == n && currSum != target) {
        return 0;
    }

    if (currSum == target && diceUsed != n) {
        return 0;
    }

    if (dp[diceUsed][currSum] != -1) {
        return dp[diceUsed][currSum];
    }

    int ans = 0;
    for (int face = 1; face <= k; face++) {
        int recAns = 0;
        if (currSum + face <= target) {
            recAns = solveUsingMemo(
                        n, k, target,
                        diceUsed + 1,
                        currSum + face,
                        dp);
        }
        ans = (ans % MOD+ recAns% MOD)% MOD;
    }

    return dp[diceUsed][currSum] = ans;
}

    
    int numRollsToTarget(int n, int k, int target) {
        int diceUsed = 0;
        int currSum = 0;
        // recursion
        // int ans = solveUsingRecursion(n, k, target,diceUsed, currSum);

        // memoisation
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
        int ans = solveUsingMemo(n, k, target,diceUsed, currSum , dp);

        return ans;
    }
};