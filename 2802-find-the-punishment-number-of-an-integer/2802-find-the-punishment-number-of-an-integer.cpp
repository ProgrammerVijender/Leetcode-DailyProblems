class Solution {
public:
    bool check(string temp, int target, int index = 0, int currentSum = 0) {
        if (index == temp.size()) {
            return currentSum == target;
        }

        int num = 0;
        for (int i = index; i < temp.size(); i++) {
            num = num * 10 + (temp[i] - '0');
            if (num + currentSum <= target) {
                if (check(temp, target, i + 1, currentSum + num)) {
                    return true;
                }
            } else {
                break;
            }
        }

        return false;
    }

    int punishmentNumber(int n) {
        int ans = 0;

        for (int i = 1; i <= n; i++) {
            string temp = to_string(i * i);
            if (check(temp, i)) {
                ans += i * i;
            }
        }

        return ans;
    }
};