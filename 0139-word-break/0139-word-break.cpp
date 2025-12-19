class Solution {
public:
    bool check(vector<string>& wordDict, string s) {
        for (auto it : wordDict) {
            if (s == it) return true;
        }
        return false;
    }

    // recursion
    // bool solve(string s, vector<string>& wordDict, int start) {

    //     if (start == s.size()) {
    //         return true;
    //     }

    //     string word = "";
    //     bool flag = false;

    //     for (int i = start; i < s.size(); i++) {
    //         word += s[i];

    //         if (check(wordDict, word)) {
    //             flag = flag || solve(s, wordDict, i + 1);
    //         }
    //     }

    //     return flag;
    // }

    // using memoisation
//     bool solveTD(string s, vector<string>& wordDict, int start, vector<int>& dp) {
//     if (start == s.size()) return true;

//     if (dp[start] != -1) return dp[start];

//     string word = "";
//     bool flag = false;

//     for (int i = start; i < s.size(); i++) {
//         word += s[i];
//         if (check(wordDict, word)) {
//             flag = flag || solveTD(s, wordDict, i + 1, dp);
//         }
//     }

//     dp[start] = flag;
//     return dp[start];
// }

// bool wordBreak(string s, vector<string>& wordDict) {
//     vector<int> dp(s.size(), -1);
//     return solveTD(s, wordDict, 0, dp);
// }
// };

 bool solveBU(string s, vector<string>& wordDict, vector<int>& dp) {
    for (int start = s.size() - 1; start >= 0; --start) {

        string word = "";
        bool flag = false;

        for (int i = start; i < s.size(); ++i) {
            word += s[i];

            if (check(wordDict, word)) {
                // i+1 is safe because dp has size s.size()+1
                flag = flag || dp[i + 1];
            }
        }

        dp[start] = flag;
    }

    return dp[0];
}

bool wordBreak(string s, vector<string>& wordDict) {
    vector<int> dp(s.size() + 1, false);
    dp[s.size()] = true;           // base case: empty suffix is always valid

    return solveBU(s, wordDict, dp);
}
};