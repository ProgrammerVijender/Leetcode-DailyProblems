class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
         int n = fruits.size();
        vector<bool> used(n, false); // To keep track of used baskets
        int unplaced = 0;

        for (int i = 0; i < n; ++i) {
            bool placed = false;
            for (int j = 0; j < n; ++j) {
                if (!used[j] && baskets[j] >= fruits[i]) {
                    used[j] = true;  // Mark this basket as used
                    placed = true;
                    break;
                }
            }
            if (!placed) {
                ++unplaced;  // Could not place this fruit
            }
        }

        return unplaced;
    }
};