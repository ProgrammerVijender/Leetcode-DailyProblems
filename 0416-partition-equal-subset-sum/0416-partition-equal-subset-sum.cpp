class Solution {
public:

    // Recursion Approach :----
    // bool solveUsingRecursion(vector<int>& arr, int index, int currSum, int target) {
    //     // base cases
    //     if (currSum == target)
    //         return true;

    //     if (index >= arr.size() || currSum > target)
    //         return false;

    //     // include current element
    //     bool include = solveUsingRecursion(arr, index + 1, currSum + arr[index], target);

    //     // exclude current element
    //     bool exclude = solveUsingRecursion(arr, index + 1, currSum, target);

    //     return include || exclude;
    // }



    // Recursion + Memoisation Approach
    // bool solveUsingMemoisation(vector<int>& arr, int index, int currSum, int target,
    //                           vector<vector<int>>& dp) {
    //     // base cases
    //     if (currSum == target)
    //         return true;

    //     if (index >= arr.size() || currSum > target)
    //         return false;

    //     if (dp[index][currSum] != -1)
    //         return dp[index][currSum];

    //     bool include = solveUsingMemoisation(
    //         arr, index + 1, currSum + arr[index], target, dp);

    //     bool exclude = solveUsingMemoisation(
    //         arr, index + 1, currSum, target, dp);

    //     return dp[index][currSum] = (include || exclude);
    // }

    
    
    // Tabulation Method
    //  bool solveUsingTabulation(vector<int>& arr, int target) {

    //     int n = arr.size();
    //     vector<vector<int>> dp(n+2 , vector<int> (target+1,0));
    //     for(int row = n; row <=n; row++)
    //     {
    //         dp[row][target] = 1;
    //     }

    //     for(int index = n-1; index >= 0; index--)
    //     {
    //         for(int s= target; s>=0; s--)
    //         {

    //     bool include =false;
        
    //     if(s + arr[index] <= target) {
    //         include = dp[index + 1] [s + arr[index]];
    //         }

    //     bool exclude = dp[index + 1] [s];
    //             dp[index][s] = (include || exclude);
    //         }
    //     }
    //     return dp[0][0];
    // }

    bool solveUsingTabSO(vector<int>& arr, int target) {
    int n = arr.size();

    vector<int> curr(target + 1, 0);
    vector<int> next(target + 1, 0);

    curr[target] = 1;
    next[target] = 1;

    for (int ind = n - 1; ind >= 0; ind--) {
        for (int s = target; s >= 0; s--) {

            bool include = 0;
            if (s + arr[ind] <= target)
                include = next[s + arr[ind]];

            bool exclude = next[s];

            curr[s] = (include || exclude);
        }
        // shifting
        next = curr;
    }

    return next[0];
}
    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            totalSum += nums[i];
        }

        // odd sum cannot be partitioned
        if (totalSum & 1)
            return false;

        int target = totalSum / 2;
        int currSum = 0;
        int index = 0;

        // using recursion 
        // return solveUsingRecursion(nums, index, currSum, target);

        // using memoisation
        // vector<vector<int> > dp(nums.size() + 1 , vector<int> (target + 1 , -1));
        // return solveUsingMemoisation(nums , index , currSum , target , dp);

        // using Tabulation method
        // return solveUsingTabulation(nums,target);

        // using SPace optimised Tabulation method
        return solveUsingTabSO(nums,target);
    }
};