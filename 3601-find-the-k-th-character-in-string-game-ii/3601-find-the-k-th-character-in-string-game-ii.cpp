class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        int n = operations.size();
        vector<long long> length(n + 1, 0);
        length[0] = 1; // "a"

        // Compute length of word after each operation
        for (int i = 0; i < n; ++i) {
            if (operations[i] == 0) {
                length[i + 1] = min(length[i] * 2, k);
            } else {
                length[i + 1] = min(length[i] * 2, k);
            }
        }

        int shifts = 0;
        // Walk backwards to determine which original character maps to position k
        for (int i = n - 1; i >= 0; --i) {
            long long half = length[i];
            if (k > half) {
                k -= half;
                if (operations[i] == 1) {
                    shifts++; // add one to total shifts
                }
            }
        }

        // Now k == 1 and word[0] == 'a' initially
        char result = 'a' + (shifts % 26);
        return result > 'z' ? result - 26 : result;
    }
};