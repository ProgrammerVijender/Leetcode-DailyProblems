class Solution {
public:
    int sol(vector<vector<int>>& events, int k, int i, vector<vector<int>>& dp) {
        if (i == events.size() || k == 0) return 0;
        
        if (dp[i][k] != -1) return dp[i][k];

        // Binary search for next event that starts after events[i][1]
        int low = i + 1, high = events.size() - 1, nextIndex = events.size();
        while (low <= high) {
            int mid = (low + high) / 2;
            if (events[mid][0] > events[i][1]) {
                nextIndex = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        int take = events[i][2] + sol(events, k - 1, nextIndex, dp);
        int notTake = sol(events, k, i + 1, dp);

        return dp[i][k] = max(take, notTake);
    }

    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end());  // sort by start time
        int n = events.size();
        vector<vector<int>> dp(n, vector<int>(k + 1, -1)); // memoization
        return sol(events, k, 0, dp);
    }
};