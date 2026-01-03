class Solution {
public:
    int MOD = 1e9 + 7;

    pair<long long, long long> solve(int n) {
        // Base case
        if (n == 1) {
            return {6, 6}; // {same, diff}
        }

        auto prev = solve(n - 1);

        long long same = (prev.first * 3 + prev.second * 2) % MOD;
        long long diff = (prev.first * 2 + prev.second * 2) % MOD;

        return {same, diff};
    }

    int numOfWays(int n) {
        auto res = solve(n);
        return (res.first + res.second) % MOD;
    }
};